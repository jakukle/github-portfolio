using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt32_Try_Catch
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Program do wyjątków ");
            Console.Write("- podaj liczbę, przez która podzielę 10: ");
            //bool rezultat = int.TryParse(Console.ReadLine(), out int liczba);
            //Console.Write("Wynik konwersji input'a na int'a: "+rezultat+"\n");
            int liczba = 4;

            try
            {
                liczba = int.Parse(Console.ReadLine());
            }
            catch (FormatException f)
            {                     
    
                Console.WriteLine("Zly format !!! " + f.Message);
                Console.WriteLine("Domyslna wartośc liczby to 4");
            }

            try
            {
                Console.WriteLine("Wynik to " + Dzielenie(liczba));
            }

            catch (DivideByZeroException f)
            {
                Console.WriteLine("Dzielisz przez 0 !!! " + f.Message);
            }

            catch (Exception e)
            {
                Console.WriteLine("O jejku! Wyjątek: " + e.Message);
            }
            finally //nie jest obowiązkowy, zawsze będzie wykonany
            {
                Console.WriteLine("DZIELENIE KONCZY SIE");
            }

            Console.ReadKey();
        }

        static float Dzielenie(int a) //moze byc public
        {
            if(a == 5)
            {
               throw new Exception("Nie mozna dzielic przez 5 !!!");
            }

            if(a == 0)
            {
               throw new Exception("Nie mozna dzielic przez 0 !!!");
                // float i chyba double nie obslugują automatycznie dzielenia przez 0 wiec trzeba stworzyc swoj wlasny wyjatek
            }

            return (float)10.0/a; // bez (float) jest double, wiec jak damy return double to nie musi być żadnego rzutowania, wystarczy 10.0 bo jak damy 10 to int
        }
    }
}
