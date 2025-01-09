using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt27_Dziedziczenie_cz2
{
    class Program
    {
        static void Main(string[] args)
        {
            Postac p1 = new Postac("Elf", 200);
            Console.WriteLine(p1.imie +  " "+ p1.punktyHP);

            Mag p2 = new Mag("Elfik", 2387, 18820);
            Console.WriteLine(p2.imie + " " + p2.punktyHP + " "+p2.mana);

            //Console.ReadKey();
        }
    }

    class Postac
    {
        public Postac()
        {

        }

        public Postac(string imie, int punktyHP)
        {
            this.imie = imie;
            this.punktyHP = punktyHP;
        }
        public string imie;
        public int punktyHP;
    }

    class Mag: Postac
    {
        public Mag(string imie, int punktyHP, int mana) : base ("Mag ma imie", punktyHP)
        {
            this.mana = mana;
        }
        public int mana;
    }
}
