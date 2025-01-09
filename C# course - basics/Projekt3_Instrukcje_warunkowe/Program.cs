using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt3_Instrukcje_warunkowe
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = -1;
            bool b = a > 0;

            if (b)
            {
                Console.WriteLine("Warunek prawdziwy");
                Console.WriteLine("Warunek prawdziwy");
            }
            else
                Console.WriteLine("Warunke NIEprawdziwy");

            if (b != true && a < 3)
                Console.WriteLine("IF zlozony");

            Console.ReadKey();

        }
    }
}
