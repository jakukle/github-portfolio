using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt15_Konstruktory_i_destruktory
{
    class Program
    {
        static void Main(string[] args)
        {
            Czlowiek adi = new Czlowiek("Anna", "Halo");
            adi.PrzedstawSie();
            adi.imie = "Bartek";
            adi.PrzedstawSie();

            Console.ReadKey();
        }
    }
}
