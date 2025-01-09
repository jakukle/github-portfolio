using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt22_Kolekcje_cz3
{
    class Program
    {
        static void Main(string[] args)
        {
            //<> typ generyczny
            Dictionary<int, string> dictionary = new Dictionary<int, string>();
            dictionary.Add(1, "Ania");
            dictionary.Add(2, "Bartek"); //indeksy czyli u mnie 1 i 2 muszą być unikalne bez obsługi wyjątki - są to unikalne klucze
            if (!dictionary.ContainsKey(2))
                dictionary.Add(2, "Katarzyna");
            else dictionary.Add(3, "Bartek");

            foreach (var item in dictionary) // var to KeyValuePair<int, string> w tym przypadku
            {
                Console.WriteLine("{0} : {1}", item.Key, item.Value);
            }

            Console.ReadKey();
        }
    }
}
