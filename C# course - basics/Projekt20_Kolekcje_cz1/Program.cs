using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt20_Kolekcje_cz1
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList list = new ArrayList();
            list.Add(232);
            list.Add("Bartek");
            list.Add(new Auto("BMW"));
            list.RemoveAt(1);

            Console.WriteLine(list.Count);
            Console.WriteLine(list[1].ToString());

            list.Insert(0, "Alesław");

            Console.WriteLine(list.Count);
            Console.WriteLine(list[1].ToString());

            foreach (var item in list)
            {
                Console.WriteLine(item);
            }

            list.Clear();

            Console.WriteLine(list.Count);

            Console.ReadKey();
            Console.ReadKey(true);
            Console.ReadKey(false);
        }
    }
    class Auto
        {
            public string Nazwa { get; set; }
            public Auto(string marka)
            {
                Nazwa = marka;
            }

            public override string ToString()
            {
                //return base.ToString();
                return Nazwa;
            }
        }
}
