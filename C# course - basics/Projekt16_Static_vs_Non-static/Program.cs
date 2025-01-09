using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt16_Static_vs_Non_static
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine(CzlowiekStatic.LiczbaLudnosci);
            CzlowiekStatic.LiczbaLudnosci = 49;
            Console.WriteLine(CzlowiekStatic.LiczbaLudnosci);

            Math.Abs(6);

            Czlowiek czlowiek = new Czlowiek();
            Console.WriteLine(czlowiek.imie);
            czlowiek.imie = "Marek";
            Console.WriteLine(czlowiek.imie);

            Czlowiek czlowiek2 = new Czlowiek();
            Console.WriteLine(czlowiek2.imie);

            Console.WriteLine(Czlowiek.liczba);
            Czlowiek.liczba = 108810;
            Console.WriteLine(Czlowiek.liczba);

            Console.ReadKey();
        }
    }
}
