using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt9_Tablice_cz1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] tab_temperatura = new int[365]; // Tablice mają z góry określoną długość w przeciwieństwie do innych kolekcji ale są za to szybkie
            string[] dni_tygodnia = { "poniedziałek", "wtorek", "środa", "czwartek", "piątek", "sobota", "niedziela" }; // Drugi sposób definiowania tablic
            //tab_temperatura[0] = 22;

            for (int i = 0; i < dni_tygodnia.Length; i++)
            {
                Console.WriteLine(dni_tygodnia.Length - i);
            }


            Console.ReadKey();
        }
    }
}
