using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt29_Interfejsy
{
    class Program
    {
        static void Main(string[] arguments)
        {
            arguments = new string[6];
            arguments[0] = "Rodzina";
            arguments[1] = "Brat ";
            arguments[2] = "Mama ";
            arguments[3] = "Tata ";
            arguments[4] = "Babcia ";
            arguments[5] = "Dziadek ";
            arguments[1] = "Córka ";
            foreach (var itemik in arguments)
            {
                Console.WriteLine(itemik);
            }

            Postac p1 = new Postac("Elf", 200);

            //deklaracja ataków w sposób jawny -> wywołanie   -    w tym projekcie nie mam jawnie zrobionie
            /*IAtakMieczem atak = (IAtakMieczem)p1;
            atak.Atak(25);
            IAtakMagiczny atak2 = (IAtakMagiczny)p1;
            atak2.Atak(50);*/

            //deklaracja ataków w sposób niejawny -> wywołanie   -   w tym projekcie mam niejawnie zrobione
            p1.Atak(75);
        }

        interface IAtakMagiczny //podobnie jak klasy lepiej tworzyć w osobnym pliku
        {
            //int abc //nie mogą zawierać pól
            void Atak(int pkt); //nie mogą zawierać ciała
            void Atak2(int pkt); //nie mogą zawierać ciała
            void Atak2(int pkt2, int pkt3); //nie mogą zawierać ciała
        }

        interface IAtakMieczem // one są jakby takimi klasami abstrakcyjnymi
        {
            void Atak(int pkt);
            void Atak3(int pkt);
        }
        class Postac : IAtakMagiczny, IAtakMieczem
        {
            public Postac (string imie, int punktyHP)
            {
                this.imie = imie;
                this.punktyHP = punktyHP;
            }
            public string imie;
            public int punktyHP;

            public void Atak(int pkt)
            {
                Console.WriteLine("Atak raczej Magiczny");
                //throw new NotImplementedException();
            }

            public void Atak2(int pkt)
            {
                throw new NotImplementedException();
            }

            public void Atak2(int pkt2, int pkt3)
            {
                throw new NotImplementedException();
            }

            public void Atak3(int pkt)
            {
                throw new NotImplementedException();
            }
        }
    }
}
