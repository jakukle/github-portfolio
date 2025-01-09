using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt12_Funkcje_cz2
{
    class Program
    {
        static void Main(string[] args)
        {
            int wynik = Dodaj(2, 4);
            Console.WriteLine(wynik);
            Console.ReadKey();
        }

        static int Dodaj(int a, int b)
        {
            int wynik = a + b;
            int wyniczek = a - b;
            if (wynik > 10)
                return wynik;
            else
                return wyniczek;
        }
    }
}
