using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt15_Konstruktory_i_destruktory
{
    class Czlowiek
    {
        public Czlowiek(string imieKonstruktora) //konstruktor
        {
            Console.WriteLine("Jestem konstruktorem");
            imie = imieKonstruktora;
        }

        public Czlowiek(string imieKonstruktora, string nazwKonstruktora) //konstruktor
        {
            Console.WriteLine("Jestem konstruktorem 2");
            imie = imieKonstruktora;
            nazwisko = nazwKonstruktora;
        }

        public string imie = "BRAK";
        public string nazwisko = "BRAK";

        public void PrzedstawSie()
        {
            Console.WriteLine("Mam na imie " + imie);
            Console.WriteLine("Mam na nazwisko " + nazwisko);
        }
        ~Czlowiek() //destruktor
        {
            Console.WriteLine("Jestem destruktorem");
            System.Diagnostics.Trace.WriteLine("Jestem destr - Diag");
        } 
    }
}
