using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt13_Funkcje_cz3
{
    class Program
    {
        static void Main(string[] args)
        {
            //int a = 9;
            //int b;
            int[] tabX = new int[2];
            tabX[0] = 49;
            tabX[1] = 62;
            Console.WriteLine("Przed funkcja: " + tabX[0] + " " + tabX[1]);
            Test2(ref tabX);
            Console.WriteLine("Po funkcji: " + tabX[0] + " " + tabX[1]);
            //Console.WriteLine("Przed: " + a);
            //Test(in a, out b);
            //Console.WriteLine("Po: " + a+ " "+b);
            Console.ReadKey();
        }

        static void Test(in int xa, out int xb) //ref to referencja czyli oryginal
        {
            xb = xa + 5;
            Console.WriteLine("W funkcji: " + xa + " " + xb);
        }

        static void Test2(ref int[] b) //ref to referencja czyli oryginal
        {
            b = new int[2];
            b[0] = 198;
            b[1] = 625;
            Console.WriteLine("W funkcji: " + b[0] + " "+ b[1]);
        }
    }
}
