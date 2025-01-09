using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt14_Klasy_i_Obiekty_cz1
{
    class Program
    {
        static void Main(string[] args)
        {
            //int x = 5;
            //int* xx = &x;
            //Console.WriteLine(x);
            //Console.WriteLine((IntPtr)xx);

            Czlowiek2 polak = new Czlowiek2();
            Console.WriteLine(polak.imie);
            polak.imie = "Bartek";
            Console.WriteLine(polak.imie);
            polak.PrzedstawSie();
            Console.WriteLine("\n\n");



            string domena_Pawelka;
            int wiek_mamy_Pawelka;
            Czlowiek Pawelek = new Czlowiek();

            domena_Pawelka = Pawelek.Getterek_moj();
            Console.WriteLine("Domena Pawelka to: " + domena_Pawelka + "\n");

            Console.WriteLine("Podaj wiek Pawelka: ");
            Pawelek.wiek = Convert.ToInt32(Console.ReadLine());
        
            int Wiek_Pawelka_za_50_lat = Pawelek.Getterek_moj_2();
            Console.WriteLine("\nWiek Pawelka za pół wieku to: " + Wiek_Pawelka_za_50_lat + "\n" );

            wiek_mamy_Pawelka = Pawelek.Wiek_mamy(in Pawelek.wiek);
            Console.WriteLine("Prawidziwy wiek twojej mamy to jednak: "+ wiek_mamy_Pawelka);

            Pawelek.Setterek_moj();
            domena_Pawelka = Pawelek.Getterek_moj();
            Console.WriteLine("\nJednak domena Pawelka to: " + domena_Pawelka + "\n");



            Console.ReadKey();
        }
    }

    class Czlowiek2
    {
        public string imie = "Adrian";

        public void PrzedstawSie()
        {
            Console.WriteLine("Mam na imie: " + imie);
        }
    }
}
