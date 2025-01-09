using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt10_Tablice_cz2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] tab1 = new int[2, 3];
            tab1[0, 0] = 19;
            tab1[0, 1] = 9;
            tab1[0, 2] = 129;
            tab1[1, 0] = 176;
            tab1[1, 0] = 26;
            tab1[1, 2] = 48;

            Console.WriteLine(tab1.Length);
            Console.WriteLine(tab1.GetLength(0)); //dlugosc 1 wymiaru
            Console.WriteLine(tab1.GetLength(1)); //dlugosc 2 wymiaru
            Console.WriteLine();

            for (int i = 0; i < tab1.GetLength(0); i++)
                for (int j = 0; j < tab1.GetLength(1); j++)
                {
                    Console.WriteLine($"{i} {j}");
                    Console.WriteLine($"{tab1[i,j]}");
                }
            Console.WriteLine();

            int[][] tab2 = new int[4][];
            tab2[0] = new int[3];
            tab2[1] = new int[2];
            tab2[1][0] = 25;
            tab2[2] = new int[5];
            tab2[3] = new int[4];

            Console.WriteLine(tab2.GetLength(0));
            Console.WriteLine(tab2.Length);
            Console.WriteLine(tab2[0].Length);
            Console.WriteLine(tab2[1].Length);
            Console.WriteLine(tab2[2].Length);
            Console.WriteLine(tab2[3].Length);
            Console.WriteLine();

            Random los = new Random();

            for (int i = 0; i < tab2.Length; i++)
            {
                for (int j = 0; j < tab2[i].Length; j++)
                {
                    //double wynik = Math.Pow(j, i);
                    //tab2[i][j] = (int)wynik;
                    tab2[i][j] = los.Next(1, 100);
                    Console.WriteLine(tab2[i][j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            foreach(int[] podtablica in tab2)
            {
                Array.Sort(podtablica);
            }
            //Array.Sort(tab2);

            for (int i = 0; i < tab2.Length; i++)
            {
                for (int j = 0; j < tab2[i].Length; j++)
                {
                    Console.WriteLine(tab2[i][j]);
                }
                Console.WriteLine();
            }

            Console.ReadKey();
        }
    }
}
