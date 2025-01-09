using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt30_Struktury
{
    class Program
    {
        static void Main(string[] args)
        {
            Punkt2D punkt1 = new Punkt2D();
            //może być Punkt2D punkt1; jest zadeklarowany ale nie ma konstruktora, nie ma 0 ale jest null
            punkt1.x = 6;
            punkt1.y = 9;
            Console.WriteLine(punkt1.x);
            Console.WriteLine(punkt1.y);
            Console.WriteLine(punkt1.OdlegloscOdSrodka());
            Console.WriteLine();

            Punkt2D punkt2; // klasy tak nie zadeklarujemy
            punkt2 = punkt1; // tutaj kolejna różcnia wzgl. klas - kopiuje się a nie jest typu referencji
                             // struktury nie są dziedziczone
            punkt2.x = 8;
            Console.WriteLine(punkt2.x);
            Console.WriteLine(punkt2.y);
            Console.WriteLine(punkt2.OdlegloscOdSrodka());
            Console.WriteLine();

            Punkt2D punkt3 = punkt1 + punkt2;
            Console.WriteLine(punkt3.x);
            Console.WriteLine(punkt3.y);
            Console.WriteLine(punkt3.OdlegloscOdSrodka());
            Console.WriteLine();

        }
    }

    //struktury też w nowym okienku lepiej
    struct Punkt2D
    {
        public Punkt2D(int x, int y)
        {
            this.x = x; //musi to być w taki sposób
            this.y = y;
        }
        public static Punkt2D operator +(Punkt2D a, Punkt2D b) //przeciążanie operatora, aby działało dodawanie wyżej
        {
            return new Punkt2D(a.x + b.x, a.y + b.y);
        }

        public int x; //nie może być inicjatorów chyba że damy public const int x = 5;
        public int y;
        public double OdlegloscOdSrodka()
        {
            return Math.Round(Math.Sqrt(Math.Pow(x, 2) + Math.Pow(y, 2)), 4);
        }
    }
}
