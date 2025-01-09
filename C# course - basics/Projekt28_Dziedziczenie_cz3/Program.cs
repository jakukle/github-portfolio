using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt28_Dziedziczenie_cz3
{
    class Program
    {
        static void Main(string[] args)
        {
            Mag p1 = new Mag("Elf podstawowy", 7, 11);
            Console.WriteLine(p1.imie +" " + p1.punktyHP + " "+ p1.mana);
            p1.Ruch();
            p1.Sila();

            Console.WriteLine();

            SuperMag p2 = new SuperMag("Elf super", 8, 12, true);
            Console.WriteLine(p2.imie + " " + p2.punktyHP + " " + p2.mana);
            p2.Ruch();
            p2.Sila();

            Console.WriteLine();

            SuperMag3 p3 = new SuperMag3("Elf super 3", 9, 13, true);
            Console.WriteLine(p3.imie + " " + p3.punktyHP + " " + p3.mana);
            p3.Ruch();
            p3.Sila();

            Console.WriteLine();

        }
    }
    abstract class Postac
    {
        public Postac(string imie, int punktyHP)
        {
            this.imie = imie;
            this.punktyHP = punktyHP;
        }

        public virtual void Ruch()
        {
            Console.WriteLine("Ruch postaci");
        }

        public abstract void Sila();

        public string imie;
        public int punktyHP;
    }

    class Mag : Postac
    {
        public Mag(string imie, int punktyHP, int mana) : base("Elf", 300)
        {
            this.mana = mana;
        }
        public override void Ruch()
        {
            base.Ruch();
            Console.WriteLine("Ruch Maga");
        }

        public override void Sila()
        {
            Console.WriteLine("Jestem Mag więc mam mało siły");
        }
        public int mana;
    }

    sealed class SuperMag : Mag //- SuperMag jest ostatnią klasą dziedziczącą w hierarchi, nikt nie może już od SuperMag odziedziczyć
    {
        public SuperMag(string imie, int punktyHP, int mana, bool good) : base(imie, 4000, 5000)
        {
            this.good = good;
            Console.WriteLine("Dobra postac");
        }
        public bool good;
    }

    /*class SuperMag2 : SuperMag
    {
        public SuperMag2(string imie, int punktyHP, int mana, bool good, bool veryLong) : base(imie, 20000, 30000, true)
        {
            veryyLong = veryLong;
        }
        public bool veryyLong;

    }*/

    class SuperMag3 : Mag
    {
        public SuperMag3(string imie, int punktyHP, int mana, bool fast) : base(imie, 6000, 7000)
        {
            this.fast = fast;
            Console.WriteLine("Szybka postac");
        }
        public bool fast;
    }
}
