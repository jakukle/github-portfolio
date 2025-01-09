using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt6_Praktyka_2_programy
{
    class Program
    {
        static void Main(string[] args)
        {
            // WYŚWIETL W KONSOLI PROSTOKĄT O SZEROKOŚCI X ORAZ WYSOKOŚCI Y
            // X ORAZ Y PODAJE UŻYTKOWANIK, PROSTOKĄT ZBUDOWANY JEST Z "*"

            /*bool flag_xs = true;
            bool flag_ys = true;
            string xs = "";
            string ys = "";

            Label1:
            if (flag_xs == true)
            {
                Console.Write("Podaj szerokość: ");
                xs = Console.ReadLine();
                flag_xs = false;
            }
            Label2:
            if (flag_ys == true)
            {
                Console.Write("Podaj wysokość: ");
                ys = Console.ReadLine();
                flag_ys = false;
            }
            int xs_int = Convert.ToInt32(xs);
            int ys_int = Convert.ToInt32(ys);

            if (xs_int < 1)
            {
                flag_xs = true;
                goto Label1;
            }
            if (ys_int < 1)
            {
                flag_ys = true;
                goto Label2;
            }

            for (int i = 1; i <= xs_int; i++)
            {
                Console.Write("X");
            }
            Console.WriteLine("");
            if (ys_int > 1)
            {
                for (int j = 1; j < ys_int - 1; j++)
                {
                    for (int i = 1; i <= xs_int; i++)
                    {
                        if ((i == 1) || (i == xs_int))
                        {
                            Console.Write("X");
                        }
                        else
                            Console.Write(" ");
                    }
                    Console.WriteLine("");
                }
                for (int i = 1; i <= xs_int; i++)
                {
                    Console.Write("X");
                }
            }
            Console.ReadKey();

            Console.WriteLine("\n");
            */
            // GRA W ZGADYWANIE LICZBY WYLOSOWANEJ PRZEZ KOMPUTER
            // KOMPUTER LOSUJE LICZBE Z ZAKRESU 1 - 10
            // UZYTKOWNIK PROBUJE ODGADNAC WYLOSOWANA LICZBE
            // JEZELI PODANA LICZBA JEST MNIEJSZA LUB WIEKSZA OD WYLOSOWANEJ - WYSWIETL KOMUNIKAT
            // KIEDY UZYTKOWNIK ODGADNIE LICZBE, WYSWIETL INFORMACJE O WYGRANEJ

            Random rnd = new Random();
            int Los = rnd.Next(1, 100);
            //Console.WriteLine(Los);
            int uzytkownik;
            int ink = 0;

            do
            {
                ink++;
                Console.WriteLine($"Proba numer: {ink}");
                Console.WriteLine("Zgadnij liczbe: ");
                uzytkownik = int.Parse(Console.ReadLine());
                if (uzytkownik < Los)
                {
                    Console.WriteLine("Podaj WIEKSZĄ liczbe");
                }
                else if (uzytkownik > Los)
                {
                    Console.WriteLine("Podaj MNIEJSZĄ liczbe");
                }
                else Console.WriteLine($"BRAWWOOOOOOO!!!!! ZGADLES GENIUSZU ZA {ink} RAZEM");
            } while (uzytkownik != Los);

            Console.ReadKey();
        }
    }
}
