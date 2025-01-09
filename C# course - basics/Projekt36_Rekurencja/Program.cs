using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt36_Rekurencja
{
    class Program
    {
        static void Main(string[] args)
        {
            const int LICZBA = 8;
            Stopwatch time = new Stopwatch();

            time.Start();
            Console.WriteLine(Silnia(LICZBA));
            time.Stop();
            Console.WriteLine(time.ElapsedTicks);
            time.Reset();

            Console.WriteLine();

            time.Start();
            Console.WriteLine(SilniaRek(LICZBA));
            time.Stop();
            Console.WriteLine(time.ElapsedTicks);

            Console.ReadKey();
        }
        private static long Silnia(int x)
        {
            long wynik = 1;
            while (x>1)
            {
                wynik *= x;
                x--;
            }
            return wynik;
        }
        private static long SilniaRek(int x)
        {
            long wynik = 1;
            if (x<=1)
            {
                return 1;
            }
            else
            {
                return SilniaRek(x-1 )*x;
            }
            
        }
    }
}
