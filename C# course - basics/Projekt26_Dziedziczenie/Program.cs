using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt26_Dziedziczenie
{
    class Program
    {
        static void Main(string[] args)
        {
            Ziemia cialoNiebieskie1 = new Ziemia();
            cialoNiebieskie1.Nazwa = "Nasza Ziemia";
            Console.WriteLine(cialoNiebieskie1.Nazwa);
            cialoNiebieskie1.RuchObrotowy();
            cialoNiebieskie1.PoraDniaINocy();
            cialoNiebieskie1.Atmosfera();

            Console.WriteLine();

            Mars cialoNiebieskie2 = new Mars();
            cialoNiebieskie2.Nazwa = "Mars, nasz sąsiad";
            Console.WriteLine(cialoNiebieskie2.Nazwa);
            cialoNiebieskie2.RuchObrotowy();
            cialoNiebieskie2.PoraDniaINocy();
            cialoNiebieskie2.Atmosfera();

            Console.ReadKey();
        }
    }

    abstract class CialoNiebieskie
    {
        public string Nazwa { get; set; }
        public void RuchObrotowy()
        {
            Console.WriteLine("Kazde cialo niebieskie posiada ruch obrotowy");
        }
    }

    abstract class Planeta : CialoNiebieskie
    {
        public void PoraDniaINocy()
        {
            Console.WriteLine("Pora Dnia i Nocy");
        }
    }

    class Ziemia : Planeta
    {
        public void Atmosfera()
        {
            Console.WriteLine("Atmosfera Ziemska");
        }
    }

    class Mars : Planeta
    {
        public void Atmosfera()
        {
            Console.WriteLine("Atmosfera Marsjanska");
        }
    }
}
