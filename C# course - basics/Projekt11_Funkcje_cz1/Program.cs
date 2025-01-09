using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt11_Funkcje_cz1
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Witaj " + args[0]);
            int a = 4;
            Add(2, a);
            Add(a, 2, a + 8);
            Add(3, 4, 89, 5);
            Add(7, 3, d: 6, tekst:"");
            Add(99, 10, 50, 40, " Kasia");
            Console.ReadKey();
        }

        static void Add(int a, int b)
        {
            int wynik = a + b;
            Console.WriteLine("Wynik dodawania: " + wynik);
        }

        static void Add(int a, int b, int c = 5)
        {
            int wynik = a + b + c;
            Console.WriteLine("Wynik dodawania: " + wynik);
        }

        static void Add(int a, int b, int c = 4, int d = 8)
        {
            int wynik = a + b + c + d;
            Console.WriteLine("Wynik dodawania: " + wynik);
        }

        static void Add(int a, int b, int c = 4, int d = 8, string tekst = "Ala")
        {
            int wynik = a + b + c + d;
            Console.WriteLine("Wynik dodawania: " + wynik + tekst);
        }
    }
}
