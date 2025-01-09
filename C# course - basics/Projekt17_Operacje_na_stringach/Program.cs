using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt17_Operacje_na_stringach
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine(GenerujTekst("Mam na imię #0 oraz mam #1 lat oraz lubie #2", "Grażyna", 72, "pierogi"));

            //Program Kasia = new Program();
            //Kasia.GenerujTekst2("Mam na imię #0 i mam #1 lat", "Adam", 22);

            //GenerujTekst3("Mam na imię #0 i mam #1 lat", "Adam", 22);

            string Napis = "Mam kota";
            Console.WriteLine(Napis);
            Napis = Napis.Replace("Mam", "Jem");
            Console.WriteLine(Napis);

            string Napisek = "Mamusia";
            Napisek = "Tatus" + 3;
            Console.WriteLine(Napisek);
            Napisek = Napisek + "Jem " + "bulki " + 4 + " razy dziennie";
            Console.WriteLine(Napisek);

            Console.ReadKey();
        }

        public static string GenerujTekst(string tekst, params object[] args)
        {
            for (int i = 0; i < args.Length; i++)
            {
                Console.WriteLine($"Rozmiar to {args.Length} + obieg petli to {i}");
                tekst = tekst.Replace("#" + i, args[i].ToString());
            }
            return tekst;
        }

        /*public string GenerujTekst2(string tekst, params object[] args) // Należy stworzyć obiekt, aby mógł tworzyć kopie metod, pól, właściwości i wtedy można z tej metody korzystać
        {
            return tekst;
        }*/

        /*static string GenerujTekst3(string tekst, params object[] args) // jest prywatna jeśli nie okeślimy modyfikatora dostępu
        {
            return tekst;
        }*/
    }
}
