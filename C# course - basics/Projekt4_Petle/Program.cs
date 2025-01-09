using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt4_Petle
{
    class Program
    {
        static void Main(string[] args)
        {
            const int PETLA = 10;
            int x = 1;
            int y = 55167;
            /*while (x < PETLA)
            {
                Console.WriteLine($"x: {x}, y: {y}");
                if (x < PETLA - 2)
                Console.WriteLine("Petla wykonuje sie");
                else Console.WriteLine("Petla KONCZY SIE");
                x += 2;
                y /= 9;
            }*/

            for(int b = 0; b<5 ; b++ )
            {
                Console.WriteLine(b);
            }

            int xx = 67;
            do
            {
                Console.WriteLine(xx);
                xx++;
            } while (xx < 4);

            Console.ReadKey();
        }
    }
}
