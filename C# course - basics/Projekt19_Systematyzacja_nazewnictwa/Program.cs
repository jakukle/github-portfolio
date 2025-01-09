using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Globalization;

namespace Projekt19_Systematyzacja_nazewnictwa
{
    class Program
    {
        static void Main(string[] args)
        {
            //var c = CultureInfo.GetCultures(CultureTypes.AllCultures);
            //foreach (var item in c)
            //{
            //    Console.Write(item.Name);
            //    Console.WriteLine(item.NumberFormat.NumberDecimalSeparator);
            //}

            Console.WriteLine(CultureInfo.CurrentCulture.Name);
            //CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator = ":";
            var newCulture = (CultureInfo)CultureInfo.CurrentCulture.Clone();
            newCulture.NumberFormat.NumberDecimalSeparator = "_";
            newCulture.NumberFormat.NegativeSign = "MINUS ";
            CultureInfo.CurrentCulture = newCulture;

            int a = -5;
            float b = 3.14f;

            Console.WriteLine($"{a}\n{b}");

            Console.ReadKey();
        }
    }
}
