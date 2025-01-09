using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt24_Equals
{
    class Program
    {
        static void Main(string[] args)
        {
            string s1 = "Program";
            string s2 = new string("Program".ToArray());
            Console.WriteLine(s1 == s2);
            Console.WriteLine(s1.Equals(s2));

            Auto auto1 = new Auto("FIAT", 1999);
            Auto auto2 = new Auto("FIAT", 1993);
            Console.WriteLine(auto1 == auto2);
            Console.WriteLine(auto1.Equals(auto2));
            Auto auto3 = auto1;
            Console.WriteLine(auto1 == auto3);

            Console.ReadKey();
        }
    }

    class Auto
    {
        public string Model { get; set; }
        public int Rocznik { get; set; }
        public Auto(string Model, int Rocznik)
        {
            this.Model = Model;
            this.Rocznik = Rocznik;
        }
        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }

        public bool Equals(Auto auto)
        {
            return auto.Model == this.Model && auto.Rocznik == this.Rocznik;
        }
    }
}
