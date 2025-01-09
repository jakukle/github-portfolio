using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt1_Zmienne_i_typy_danych
{
    class Program
    {
        static void Main(string[] args)
        {
            int ZmiennaPierwsza = 1;
            int MaxZmiennaInt = int.MaxValue;
            Console.WriteLine(MaxZmiennaInt);
            string ZmiennaPierwszaStr = ZmiennaPierwsza.ToString();
            string ZmiennaDruga = "Twoja konsola bracie";
            Console.WriteLine("Hahaha");
            Console.WriteLine($"{ZmiennaPierwszaStr} { ZmiennaDruga}");
            double zmiennaTrzecia = 6.84;

            byte zmiennaCzwarta = byte.MaxValue;
            byte zmiennaCzwarta2 = byte.MinValue;
            sbyte zmiennaPiąta = sbyte.MaxValue;
            sbyte zmiennaPiąta2 = sbyte.MinValue;
            int ZmiennaSzosta = int.MaxValue;
            uint ZmiennaSzosta2 = uint.MaxValue;
            long ZmiennaSiodma = long.MinValue;
            ulong ZmiennaSiodma2 = ulong.MaxValue;

            float zmienna11 = 1.143f;
            double zmienna12 = 3.3223;
            decimal zmienna13 = 93.2312m;

            string zmienna14 = "1";
            char zmienna15 = 'a';

            var zmienna17 = zmienna15;

            bool zmienna16 = 5>33;
            Console.WriteLine(zmienna16);

            const byte JAKUB = 7;

            Console.ReadKey();
        }
    }
}
