using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt31_Enum
{
    enum PoryRoku :sbyte//też może być to osobny plik i mamy do wyboru typ
    {
        Wiosna = 2, Lato, Jesień = 1, Zima = 2
    }
    class Program
    {
        static void Main(string[] args)
        {
            PoryRoku poraRoku = PoryRoku.Wiosna;
            Console.WriteLine((int)poraRoku);
            Console.WriteLine(poraRoku);

            Console.WriteLine();

            poraRoku = (PoryRoku)3;
            Console.WriteLine((int)poraRoku);
            Console.WriteLine(poraRoku);

            Console.WriteLine();

            poraRoku = (PoryRoku)65;
            Console.WriteLine((int)poraRoku);
            Console.WriteLine(poraRoku);


            Console.WriteLine();

            poraRoku = (PoryRoku)2;
            Console.WriteLine((int)poraRoku);
            Console.WriteLine(poraRoku);

            Console.WriteLine();

            poraRoku = (PoryRoku)1;
            Console.WriteLine((int)poraRoku);
            Console.WriteLine(poraRoku);

            Console.WriteLine();

            poraRoku = (PoryRoku)3;
            Console.WriteLine((int)poraRoku);
            Console.WriteLine(poraRoku);
        }
    }
}
