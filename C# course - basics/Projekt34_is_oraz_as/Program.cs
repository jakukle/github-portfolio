using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt34_is_oraz_as
{
    class Program
    {
        static void Main(string[] args)
        {

            //is

            //Zwierze zwierze = new Zwierze();
            //Kot kot = new Kot();
            //zwierze = kot; jest git

            /*zwierze = new Kot();
            kot = (Kot)zwierze;
            kot.PijMleko();*/

            /*Console.WriteLine(kot is Kot);
            Console.WriteLine(kot is Zwierze);
            Console.WriteLine(zwierze is Kot); //tutaj nie rzutujemy bo to niebezpieczne - nie robimy Kot kot2 = (Kot)zwierze
            Console.WriteLine(zwierze is Zwierze);
            zwierze = kot; //dzieki tej linijce możemy rzutować (choć dalej to nieprofesjonalne) Kot kot2 = (Kot)zwierze bo teraz is zwroci nam true
            if (kot is Kot)
            {
                Console.WriteLine("Powiodlo sie - kot to Kot");
            }
            else
            {
                Console.WriteLine("Nie powiodlo sie - kot to nie Kot");
            }

            if (kot is Zwierze)
            {
                Console.WriteLine("Powiodlo sie - kot to Zwierze");
            }
            else
            {
                Console.WriteLine("Nie powiodlo sie - kot to nie Zwierze");
            }
            if (zwierze is Kot)
            {
                Console.WriteLine("Powiodlo sie - zwierze to Kot");
            }
            else
            {
                Console.WriteLine("Nie powiodlo sie - zwierze to nie Kot");
            }
            if (zwierze is Zwierze)
            {
                Console.WriteLine("Powiodlo sie - zwierze to Zwierze");
            }
            else
            {
                Console.WriteLine("Nie powiodlo sie - zwierze to nie Zwierze");
            }*/

            //as

            Zwierze zwierze = new Kot();//albo Zwierze zwierze = new Zwierze() i zwierze = kot
            //Kot kot2 = (Kot)zwierze; //(niezpieczne)
            Kot kot2 = zwierze as Kot; //(bezpieczne) - próbuje, ale może się nie udać (niepowodzenie to zmieni się na NULL - referencja na pusty obiekt)
            if (!(kot2 == null))
            {
                kot2.PijMleko();
                Console.WriteLine("Powiodlo sie - zwierze (kot2) to Kot");
            }
            else
            {
                Console.WriteLine("Nie powiodlo sie - zwierze (kot2) to nie Kot");
            }
        }
    }

    class Zwierze
    {
        public virtual void DajGlos()
        {
            Console.WriteLine("Domyslny glos");
        }

    }
    class Kot : Zwierze
    {
        public override void DajGlos()
        {
            Console.WriteLine("Kot miauczy");
        }

        public void PijMleko()
        {
            Console.WriteLine("Kot pije mleko");
        }

    }
}
