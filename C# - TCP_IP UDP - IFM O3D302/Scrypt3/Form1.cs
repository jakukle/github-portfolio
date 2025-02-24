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
using System.Threading;

namespace App_test_3
{
    public partial class Form1 : Form
    {
        private UdpClient udpClient;
        private Thread receiveThread;
        private int port = 3321;
        public Form1()
        {
            InitializeComponent();
            StartUdpListener();
        }
        private void StartUdpListener()
        {
            udpClient = new UdpClient(port);
            receiveThread = new Thread(new ThreadStart(ReceiveData));
            receiveThread.IsBackground = true;
            receiveThread.Start();
        }
        private void ReceiveData()
        {
            IPEndPoint remoteEndPoint = new IPEndPoint(IPAddress.Any, port);
            while (true)
            {
                try
                {
                    byte[] receiveBytes = udpClient.Receive(ref remoteEndPoint);
                    string receivedData = Encoding.ASCII.GetString(receiveBytes);
                    Console.WriteLine("Received data: " + receivedData); // Dodano
                    AppendText(receivedData);
                }
                catch (Exception ex)
                {
                    AppendText("Error: " + ex.Message);
                    Console.WriteLine("Error: " + ex.Message); // Dodano
                }
            }
        }
        private void AppendText(string text)
        {
            if (InvokeRequired)
            {
                this.Invoke(new Action<string>(AppendText), new object[] { text });
                return;
            }
            textBox1.AppendText(text + Environment.NewLine);
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (receiveThread != null && receiveThread.IsAlive)
            {
                receiveThread.Abort();
            }
            udpClient.Close();
        }
    }
}
