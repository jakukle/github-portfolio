using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt5_Konwersje_i_rzutowanie
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine();
            Console.WriteLine("Program 5 - Konwersje i rzutowanie");
            /*Console.WriteLine();
            Console.WriteLine();*/

            //PRZYDATNE SKROTY

            // ctrl k oraz ctrl d - poprawne/przejrzyste sformatowanie kodu
            // ctrl k oraz ctrl c - zaznaczone zmienia sie w komentarz
            // ctrl k oraz ctrl u - zaznaczone zmienia sie w NIEkomentarz
            // f5 - szybka kompilacja i uruchomienie

            //PRZYDATNE SNIPETY

            // cw plus szybko 2x tab - Console.WriteLine()
            // for plus szybko 2x tab - petla for sie automatycznie uzupelnia

            //RZUTOWANIE ZMIENNYCH

            /*int i = int.MaxValue;
            short s = short.MaxValue;
            s = (short)i;
            Console.WriteLine(s);*/

            //WCZYTYWANIE DANYCH Z KONSOLI

            /*string str = Console.ReadLine();
            Console.WriteLine(str);*/

            /*Console.WriteLine("----------PIERWSZY ETAP - IF----------");

            if (Console.ReadKey().Key == ConsoleKey.D1)
            {
                Console.WriteLine(" PRAWDA");
            }
            else
                Console.WriteLine(" FALSZ");

            Console.WriteLine("----------DRUGI ETAP - RAZEM (2 LINIJKI)----------");

            Console.WriteLine($"TO JEST D1: {ConsoleKey.D1}");
            Console.WriteLine($" TO JEST Key: {Console.ReadKey().Key}");

            Console.WriteLine("----------TRZECI ETAP - ODDZIELNIE (4 LINIJKI)----------");

            Console.WriteLine("TO JEST D1");
            Console.WriteLine(ConsoleKey.D1);
            Console.WriteLine("TO JEST Key");
            Console.WriteLine($" {Console.ReadKey().Key}");*/

            //KONWERSJE STRING

            //string s = Console.ReadLine();

            //int i = int.Parse(s + 2);
            /*int i = Convert.ToInt32(s + 2);
            Console.WriteLine(i);
            i = int.Parse(s+2)- 3;
            Console.WriteLine(i);

            s = i.ToString();
            Console.WriteLine(s);*/

            /*int i = 12;
            Console.WriteLine(i);
            bool r = int.TryParse(s + 2, out i);
            Console.WriteLine(i);
            Console.WriteLine($"Rezultat operacji: {r}");
            bool rr = int.TryParse(s+2, out i);
            Console.WriteLine(i-3);
            Console.WriteLine($"Rezultat operacji: {rr}");*/

            //LACZENIE TEKSTU I FORMATOWANIE WRITELINE

            int wyniczek = 16;
            string s1 = "Witaj";
            string s2 = " Świecie!";
            string s3 = s1 + s2;
            Console.WriteLine(s3);
            //Console.WriteLine(s1 + s2 + " " + s3 + " CO JEST");

            Console.WriteLine(s1 + "{0}\n{1}", s2, wyniczek);
            Console.ForegroundColor = ConsoleColor.DarkMagenta;
            Console.WriteLine($"{s1}{s2}");
            Console.ResetColor();
            Console.WriteLine($"{s1}{s2}");
            Console.ReadKey();
            Console.Clear();


            //MODYFIKACJA WYGLĄDU KONSOLI

            //Linijka 95 i potem kolejne


            Console.ReadKey();
        }
    }
}
