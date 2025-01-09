using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt18_String_Builder
{
    class Program
    {
        static void Main(string[] args)
        {
            //Konkatynacja jest czasochłonna

            Stopwatch stopwatch = new Stopwatch();

            int ile = 10000;

            stopwatch.Start();
            BudujString(ile);
            stopwatch.Stop();
            Console.WriteLine("Standardowa metoda - konkatynacja: {0} ms oraz {1} tickow zegara", stopwatch.ElapsedMilliseconds, stopwatch.ElapsedTicks);

            stopwatch.Reset();

            stopwatch.Start();
            BudujStringBuilder(ile);
            stopwatch.Stop();
            Console.WriteLine("Metoda budowania z gotowej funkcji: {0} ms oraz {1} tickow zegara", stopwatch.ElapsedMilliseconds, stopwatch.ElapsedTicks);

            Console.ReadKey();
        }

        /// <summary>
        /// Metoda buduje string - Jakub Klepacz - zwykła konkatynacja
        /// </summary>
        /// <param name="ile">Podaj długość pętli</param>
        /// <returns>Zwracamy gotowy tekst</returns>
        public static string BudujString(int ile)
        {
            string tekst = "";
            for (int i = 0; i < ile; i++)
            {
                tekst += i;
            }
            return tekst;
        }

        public static string BudujStringBuilder(int ile)
        {
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < ile; i++)
            {
                stringBuilder.Append(i);
            }
            return stringBuilder.ToString();
        }
    }
}
