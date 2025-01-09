using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Forms2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //this.KeyPress += new KeyPressEventHandler(Form1_KeyPress);  // Podłącz zdarzenie KeyPress do formularza
            //this.AcceptButton = button1;
            this.KeyDown += new KeyEventHandler(Form1_KeyDown); //Tutaj dodajesz zdarzenie KeyDown dla formularza Form1. Zdarzenie KeyDown jest wywoływane, gdy jakikolwiek klawisz jest naciskany. Dodajesz tutaj Form1_KeyDown jako metodę obsługi tego zdarzenia.
            this.KeyPreview = true; // To allow the form to capture key events
                                    //Ustawienie tej właściwości na true pozwala formularzowi przechwytywać zdarzenia klawiatury przed przekazaniem ich do kontrolki. To oznacza, że formularz może najpierw obsłużyć każde naciśnięcie klawisza, zanim zostanie ono przekazane do aktywnej kontrolki (np. przycisku, pola tekstowego)
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(progressBar1.Value < 100)
            {
                if(textBox1.Text.Length > 0)
                {
                    if(listBox1.Items.Contains(textBox1.Text))
                    {
                        DialogResult result = MessageBox.Show("Element już istnieje! Czy chcesz dodać taki sam?", "Błąd!", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                        if(result == DialogResult.No)
                        {
                            return;
                        }
                    }
                    listBox1.Items.Add(textBox1.Text);
                    AktualizujProgres();
                    textBox1.Text = "";
                }
                else
                {
                    MessageBox.Show("Wartość jest pusta!", "Błąd!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                MessageBox.Show("Lista jest już pełna!", "Błąd!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void AktualizujProgres()
        {
            int i = listBox1.Items.Count;
            progressBar1.Value = i * 10;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int i = listBox1.SelectedIndex; //-1 nic nie zaznaczone, a jak od 0 do x to coś
            if (i != -1)
            {
                listBox1.Items.RemoveAt(i);
                AktualizujProgres();
            }
            else
            {
                MessageBox.Show("Nic nie zaznaczyłeś!", "Błąd!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            AktualizujProgres();
        }
        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter)
            {
                button1.PerformClick(); // 'button1' to nazwa przycisku
            }
        }
        private void Form1_KeyDown(object sender, KeyEventArgs e) 
        {
            if (e.KeyCode == Keys.Enter) // jeśli będzie enter (ma swoją dodatkową wewnętrzną obsługę) to Focus() rujnuje działanie poprawne kodu
            { 
                //button1.Focus(); 
                button1.PerformClick(); 
                e.Handled = true; //Informuje system, że zdarzenie zostało obsłużone i nie powinno być przekazywane dalej
                e.SuppressKeyPress = true; //Blokuje domyślne działanie klawisza, co zapobiega generowaniu dźwięku systemowego przy naciśnięciu Enter.
            }
            else if (e.KeyCode == Keys.Delete) //&& !(textBox1.Text.Length>0 && listBox1.SelectedIndex == -1))
            {
                //button2.Focus();
                button2.PerformClick();
                e.Handled = true; 
                e.SuppressKeyPress = true;
            }
            else if (e.KeyCode == Keys.NumPad0) //&& !(textBox1.Text.Length>0 && listBox1.SelectedIndex == -1))
            {
                //button2.Focus();
                button3.PerformClick();
                e.Handled = true;
                e.SuppressKeyPress = true;
            }
        }
    }
}
