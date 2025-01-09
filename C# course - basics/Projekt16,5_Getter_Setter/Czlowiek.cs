using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt16_5_Getter_Setter
{
    class Czlowiek
    {
        public string imie;


        // 1 sposób - settery, gettery

        /*private int wiek;
        public int getWiek()
        {
            return wiek;
        }

        public void setWiek(int w)
        {
            if (w >=0 && w <= 200)
            wiek = w;
        }*/


        // 2 sposób - snippety
        //public int MyProperty_wiek2 { get; set; }
        //public int MyProperty_wiek2 { get; } // tylko do odczytu


        // 3 sposób - snippety bardziej rozbudowane - propfull

        private int myAge;

        public int Age
        {
            get { return myAge + 39; }
            set 
            {
                if (value >= 0 && value < 201)
                    myAge = value;
                else
                    myAge = 0;
            }
        }

    }
}
