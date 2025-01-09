using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt14_Klasy_i_Obiekty_cz1
{
    class Czlowiek
    {
        private string domena = "Eukarionty";

        public int wiek = 0;

        private int Wiek_za_50_lat(in int wiek)
        {
            int wiek_50 = wiek + 50;
            return wiek_50;
        }

        public int Wiek_mamy(in int a)
        {
            int sredni_wiek_mamy = a + 25;
            int wiek_twojej_mamy = 0;
            
            Console.WriteLine("Podaj wiek swojej mamy: ");
            try
            {
                wiek_twojej_mamy = Convert.ToInt32(Console.ReadLine());
            }
            catch (FormatException ix)
            {
                Console.WriteLine("Wystapil wyjatek: " + ix.Message);
            }
            catch (Exception ixx)
            {
                Console.WriteLine("Wystapil inny wyjatek: " + ixx.Message);
            }
            Console.WriteLine("\nSredni wiek mamy przy wieku dziecka jak ty to: " + sredni_wiek_mamy + "\n");
            return wiek_twojej_mamy;
        }
        public string Getterek_moj()
        {
            return domena;
        }

        public int Getterek_moj_2()
        {
            return Wiek_za_50_lat(wiek);
        }

        public void Setterek_moj()
        {
            domena = "Æwieræcz³owiek";
        }
    }
}
