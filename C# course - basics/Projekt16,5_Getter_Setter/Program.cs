using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt16_5_Getter_Setter
{
    class Program
    {
        static void Main(string[] args)
        {
            Czlowiek adi = new Czlowiek();
            adi.imie = "Adrian";


            // 1 sposób

            /*adi.setWiek(82);
            adi.setWiek(-201);

            Console.WriteLine($"Jestem {adi.imie} i mam {adi.getWiek()} lat");*/


            // 2 sposób

            /*adi.MyProperty_wiek2 = 28;
            adi.MyProperty_wiek2 = -94;

            Console.WriteLine($"Jestem {adi.imie} i mam {adi.MyProperty_wiek2} lat");*/

            // 3 sposob

            adi.Age = 28;
            //adi.Age = -94;

            Console.WriteLine($"Jestem {adi.imie} i mam {adi.Age} lat");
            Console.ReadKey();
        }
    }
}
