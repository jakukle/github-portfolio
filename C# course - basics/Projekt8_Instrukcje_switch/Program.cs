using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt8_Instrukcje_switch
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 0;
            Label1:
            bool rzutowanie = int.TryParse(Console.ReadLine(), out int liczba);

            switch(liczba)
            {
                case 1:
                    Console.WriteLine("Przypadek 1");
                    break;
                case 2:
                    Console.WriteLine("Przypadek 2");
                    goto Label1;
                default:
                    Console.WriteLine("Przpadek defaultowy");
                    break;
            }

            x++;
            Console.WriteLine($"5 razy moze wykonac się przypadek 1 i defaultowy razem wziete, a jest juz: {x}");
            if (x<5)
                
                
                goto Label1;

            Console.ReadKey();

            // MOZNA TEZ W INSTRUKCJI SWITCH UZYWAĆ NP. CHAR'ow (ZNAKI)
        }
    }
}
