using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt2_Operatory_arytmetyczne
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 2;
            int b = 3;
            int c;
            c = a + b;
            a += 9;
            a--;
            bool x = c > a;
            Console.WriteLine(c);
            Console.WriteLine(a);
            Console.WriteLine(x);

            a = 2 + 3 * 4;
            Console.WriteLine(a);

            x = 1 == 1 || 1 != 1;
            Console.WriteLine(x);

            Console.WriteLine(Math.Pow(5, 4));
            

            Console.ReadKey();
        }
    }
}
