using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt21_Kolekcje_cz2
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Auto> list = new List<Auto>(); //Lista generyczna, która ma zdefiniowany typ w przeciwieństwie do ArrayList
            list.Add(new Auto ("BMW"));
            list.Add(new Auto("Mercedes"));
            list.Add(new Auto("BMW"));
            list.Add(new Auto("Audi"));
            list.Add(new Auto("Audi"));
            list.Add(new Auto("Skoda"));
            list.Add(new Auto("Audi"));
            list.Add(new Auto("Skoda"));
            list.Add(new Auto("Audi"));

            foreach (Auto item in list)
            {
                Console.WriteLine(item.Nazwa);
            }

            for (int i = 0; i< list.Count; i++)
            {
                if (i % 2 == 1)
                {
                    Console.Write("Stan wywołania funkcji do uruchomienia silnika: " + list[i].UruchomSilnik(true));
                    Console.WriteLine("    Uruchomiono silnik dla: " + list[i].Nazwa);
                }
                else
                {
                    Console.Write("Stan wywołania funkcji do uruchomienia silnika: " + list[i].UruchomSilnik(false));
                    Console.WriteLine("   Nie uruchomiono silnik dla: " + list[i].Nazwa);
                }
            }
            
            Console.ReadKey();
        }
    }
    class Auto
    {
        public string Nazwa { get; set; }
        public Auto(string marka)
        {
            Nazwa = marka;
        }
        public bool UruchomSilnik(in bool engine_starting)
        {
            bool engine_action;
            if (engine_starting == true)
            engine_action = true;
            else engine_action = false;
            return engine_action;
        }
    }
}
