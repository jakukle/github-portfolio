using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt33_Wyjątki_cz2
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Wynik = " +Dzielenie(5));
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine("Dzielisz przez 0 !!! "+ e.Message);
            }

            catch (DivideByFiveException e)
            {
                Console.WriteLine("Dzielisz przez liczbę 5 !!!\n" + e.Message); // to sie wyswietla jako 3 i 4
            }
            catch (Exception e)
            {
                Console.WriteLine("Coś poszło nie tak !!! " + e.Message);
            }

            Console.ReadKey();
        }

        public static float Dzielenie(int a)
        {
            if (a == 5)
            {
                throw new DivideByFiveException("Moj wyjatek");
            }
            return 10 / a; // wynik to int
        }
    }

    class DivideByFiveException : Exception
    {
        public DivideByFiveException(string messenger) : base(messenger + " dopisek")
        {
           Console.WriteLine(messenger); // to sie wyswietla jako 1
           Console.WriteLine(Message); // to sie wyswietla jako 2
        }
        //public override string Message => base.Message;
        //To jest troche bez sensu bo deleguje Message odziedziczone do message wlasnie z tej klasy bazowej wiec i tak sie wyswietli to co jest w klasie bazowej
        //Mozna wiec powiedziec ze ta linijka nic nie zmienia

        /*public override string Message
        {
            get { return "Nadpisanie Message'a"; }

        }*/
    }

}
