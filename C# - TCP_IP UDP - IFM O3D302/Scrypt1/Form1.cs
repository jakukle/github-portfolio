/* 1 kod - UDP
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;

namespace App_test
{
    public partial class Form1 : Form
    {
        UdpClient Client = new UdpClient(3321); //Port Number
        string data = "";
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                Client.BeginReceive(new AsyncCallback(recv), null);
            }
            catch(Exception ex)
            {
                richTextBox1.Text += ex.Message.ToString();
            }
        }

        void recv(IAsyncResult res)
        {
            IPEndPoint RemoteIP = new IPEndPoint(IPAddress.Any, 0);
            byte[] received = Client.EndReceive(res, ref RemoteIP);
            data = Encoding.UTF8.GetString(received);

            //to avoid cross-threading we use Method Invoker
            this.Invoke(new MethodInvoker(delegate
            {
                richTextBox1.Text += "\nReceived data: " + data;
            }));

            Client.BeginReceive(new AsyncCallback(recv), null);
        }
    }
}*/

// 2 kod - UDP
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;

namespace App_test
{
    public partial class Form1 : Form
    {
        UdpClient udpServer;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                udpServer = new UdpClient(3321);
                udpServer.Client.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReuseAddress, true);
                udpServer.BeginReceive(new AsyncCallback(Recv), null);
                richTextBox1.AppendText("Nasłuchiwanie na porcie 3321...\n");
            }
            catch (Exception ex)
            {
                richTextBox1.AppendText("Błąd: " + ex.Message + "\n");
            }
        }
        private void Recv(IAsyncResult res)
        {
            IPEndPoint remoteEP = new IPEndPoint(IPAddress.Any, 0);
            byte[] received = udpServer.EndReceive(res, ref remoteEP);
            string message = Encoding.UTF8.GetString(received);
            // Avoid cross-threading issues 
            this.Invoke(new MethodInvoker
                (delegate 
                {
                    richTextBox1.AppendText("Otrzymano wiadomość: " + message + " od " + remoteEP + "\n");
                }));
            udpServer.BeginReceive(new AsyncCallback(Recv), null);
        }
    }
}

/* 3 kod - Komunikacja TCP/IP
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace App_test
{
    public partial class Form1 : Form
    {
        private TcpListener tcpListener;
        private Thread listenThread;
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            int port = 50010;
            tcpListener = new TcpListener(IPAddress.Any, port);
            listenThread = new Thread(new ThreadStart(ListenForClients));
            listenThread.Start();
            richTextBox1.AppendText($"Nasłuchiwanie na porcie {port}...\n");
        }
        private void ListenForClients()
        {
            tcpListener.Start();
            while (true)
            {
                TcpClient client = tcpListener.AcceptTcpClient();
                Thread clientThread = new Thread(new ParameterizedThreadStart(HandleClientComm));
                clientThread.Start(client);
            }
        }
        private void HandleClientComm(object client_obj)
        {
            TcpClient tcpClient = (TcpClient)client_obj;
            NetworkStream clientStream = tcpClient.GetStream();
            byte[] message = new byte[4096];
            int bytesRead;
            while (true)
            {
                bytesRead = 0;
                try
                {
                    bytesRead = clientStream.Read(message, 0, 4096);
                }
                catch
                {
                    break;
                }
                if 
                    (bytesRead == 0)
                {
                    break;
                }
                string receivedData = Encoding.UTF8.GetString(message, 0, bytesRead);
                // Unikaj problemów z cross-threadingiem 
                this.Invoke(new MethodInvoker(delegate 
                {
                    richTextBox1.AppendText("Otrzymano dane: " + receivedData + "\n");
                }));
            }
            tcpClient.Close();
        }
    }
}*/

/* 4 kod - TCP/IP pod bycie klientem
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
namespace App_test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            // Dane serwera do połączenia 
            string serverIP = "192.168.0.21"; // Adres IP serwera 
            int port = 50010; // Numer portu serwera 
            try
            {
                // Tworzenie klienta TCP 
                TcpClient client = new TcpClient(serverIP, port);
                richTextBox1.AppendText("Połączono z serwerem.\n");
                // Strumień danych 
                NetworkStream stream = client.GetStream();
                // Wysyłanie danych do serwera 
                string message = "Wiadomość od klienta";
                byte[] data = Encoding.UTF8.GetBytes(message);
                stream.Write(data, 0, data.Length);
                richTextBox1.AppendText("Wysłano: " + message + "\n");
                // Odbieranie danych od serwera 
                data = new byte[4096]; //było 256
                int bytes = stream.Read(data, 0, data.Length);
                string responseData = Encoding.UTF8.GetString(data, 0, bytes);
                richTextBox1.AppendText("Otrzymano: " + responseData + "\n");
                // Zamknięcie połączenia 
                stream.Close();
                client.Close();
                richTextBox1.AppendText("Połączenie zamknięte.\n");
            }
            catch (Exception ex)
            {
                richTextBox1.AppendText("Błąd: " + ex.Message + "\n");
            }
        }
    }
}*/

/* 5 kod - TCP/IP pod bycie klientem bez wysyłania i w pętli
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Windows.Forms;
namespace App_test
{
    public partial class Form1 : Form
    {
        private Thread receiveThread;
        private TcpClient client;
        private NetworkStream stream;
        private bool isReceiving;
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            // Dane serwera do połączenia 
            string serverIP = "192.168.0.21";
            // Adres IP serwera 
            int port = 50010;
            // Numer portu serwera 
            try
            {
                // Tworzenie klienta TCP 
                client = new TcpClient(serverIP, port);
                stream = client.GetStream();
                richTextBox1.AppendText("Połączono z serwerem.\n");
                // Uruchomienie wątku odbierającego dane 
                isReceiving = true;
                receiveThread = new Thread(ReceiveData);
                receiveThread.Start();
            }
            catch (Exception ex)
            {
                richTextBox1.AppendText("Błąd: " + ex.Message + "\n");
            }
        }
        private void ReceiveData()
        {
            try
            {
                byte[] data = new byte[4096];
                while (isReceiving)
                {
                    int bytes = stream.Read(data, 0, data.Length);
                    if (bytes > 0)
                    {
                        string receivedData = Encoding.UTF8.GetString(data, 0, bytes);
                        this.Invoke(new MethodInvoker(delegate 
                        {
                            richTextBox1.AppendText("Otrzymano: " + receivedData + "\n");
                        }));
                    }
                }
            } catch (Exception ex)
            {
                this.Invoke(new MethodInvoker(delegate 
                { richTextBox1.AppendText("Błąd: " + ex.Message + "\n");
                }));
            }
            finally
            {
                stream.Close();
                client.Close();
                this.Invoke(new MethodInvoker(delegate 
                { richTextBox1.AppendText("Połączenie zamknięte.\n");
                }));
            }
        }
        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            isReceiving = false; base.OnFormClosing(e);
        }
    }
}*/