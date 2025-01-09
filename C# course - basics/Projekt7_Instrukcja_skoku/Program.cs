using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt7_Instrukcja_skoku
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 0;
            while (true)
            {
                if (a > 10)
                {
                    break;
                }
                Console.WriteLine(a);
                a++;
            }
            Console.WriteLine($"Za petla: {a}");

            Console.ReadKey();

            a = 0;

            for (int i = 0; i <= 10; i++)
            {
                if (i % 2 == 1)
                {
                    continue;
                }
                Console.WriteLine(i);
            }
            Console.ReadKey();

            bool flag_1 = false;
            bool flag_2 = false;
            bool flag_3 = false;

            a = 0;

        jeden:
            if (flag_1)
            {
                Console.WriteLine($"NIEPARZYSTA: {a}");
                flag_1 = false;
                a++;
                goto trzy;
            }

        dwa:
            if(flag_2)
            {
                Console.WriteLine($"PARZYSTA: {a}");
                flag_2 = false;
                a++;
            }

        trzy:
            if(flag_3)
            {
                Console.WriteLine($"KONIEC PETLI: {a}");
                flag_3 = false;
                a++;
            }
            

            while (a<=10)
            {
                if (a % 2 == 1)
                {
                    flag_1 = true;
                    goto jeden;
                }
                else
                {
                    flag_2 = true;
                    goto dwa;
                }
            }
            
            if (a==11)
            {
                flag_3 = true;
                goto trzy;
            }

            Console.WriteLine($"OSTATNIE 'a' PRZED KOŃCEM PROGRAMU WYNOSI: {a}");

            Console.ReadKey();
        }
    }
}
