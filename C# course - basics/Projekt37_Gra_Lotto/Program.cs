using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt37_Gra_Lotto_cz1
{
    class Program
    {
        static int kumulacja;
        static int START = 30;
        static Random rnd = new Random(0);

        static void Main(string[] args)
        {
            int pieniadze = START;
            int dzien = 0;
            do //dzien
            {
                pieniadze = START;
                dzien = 0;
                ConsoleKey wybor;
                do
                {
                    kumulacja = rnd.Next(2, 37) * 1000000;
                    dzien++;
                    int losow = 0;
                    List<int[]> kupon = new List<int[]>();
                    do
                    {
                        //MAIN MENU
                        Console.Clear();
                        Console.WriteLine("DZIEŃ: {0}", dzien);
                        Console.WriteLine("Witaj w grze LOTTO, dziś do wygrania" +
                            " jest aż {0} zł", kumulacja);
                        Console.WriteLine("\nStan konta: {0}zł", pieniadze);
                        WyswietlKupon(kupon);

                        if (pieniadze >= 3 && losow < 8)
                        {
                            Console.WriteLine("\nKlawisz 1      - Postaw los - 3zł [{0}/8]", losow + 1);
                        }
                        Console.WriteLine("Inne klawisze  - Sprawdź kupon - losowanie");
                        Console.WriteLine("Klawisz Escape - Zakończ grę");
                        //MAIN MENU
                        wybor = Console.ReadKey().Key;
                        if (wybor == ConsoleKey.D1 && pieniadze >= 3 && losow < 8)
                        {
                            kupon.Add(PostawLos());
                            pieniadze -= 3;
                            losow++;
                        }
                    } while (wybor == ConsoleKey.D1);
                    Console.Clear();
                    if (kupon.Count > 0 && wybor != ConsoleKey.Escape) //tutaj moja wstawka
                    {
                        int wygrana = Sprawdz(kupon);
                        if (wygrana > 0)
                        {
                            Console.ForegroundColor = ConsoleColor.Green;
                            Console.WriteLine("\nBrawo wygrałeś {0}zł w tym losowaniu", wygrana);
                            Console.ResetColor();
                            pieniadze += wygrana;
                        }
                        else
                        {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("\nNiestety nie wygrałes nic");
                            Console.ResetColor();
                        }
                    }
                    else if (wybor != ConsoleKey.Escape)
                    {
                        Console.WriteLine("Nie mialeś losów w tym losowaniu.");
                    }
                    Console.WriteLine("Wciśnij dowolny przycisk, aby kontynuować");
                    Console.ReadKey();
                } while (pieniadze >= 3 && wybor != ConsoleKey.Escape); ;

                Console.Clear();
                Console.WriteLine("Dzien {0}.\nKoniec gry, twój wynik to: {1}" +
                    "zł", dzien, pieniadze - START);
                Console.Write("Enter - graj od nowa\nInny przycisk - zakończ grę ");
            } while (Console.ReadKey().Key == ConsoleKey.Enter);
            Console.WriteLine();
        }

        private static int Sprawdz(List<int[]> kupon)
        {
            int[] wylosowane = new int[6];
            for (int i = 0; i < wylosowane.Length; i++)
            {
                int los = rnd.Next(1, 50);
                if (!wylosowane.Contains(los))
                {
                    wylosowane[i] = los;
                }
                else
                {
                    i--;
                }
            }
            Array.Sort(wylosowane);
            Console.WriteLine("Wylosowane liczby to: ");
            foreach (var liczba in wylosowane)
            {
                Console.Write(liczba + ", ");
            }
            int[] trafione = SprawdzKupon(kupon, wylosowane);
            int wartosc = 0;
            int wygrana = 0;
            Console.WriteLine();
            if (trafione[0] > 0)
            {
                wartosc = trafione[0] * 24;
                Console.WriteLine("3 Trafienia: {0} raz(y) + {1}zł", trafione[0], wartosc);
                wygrana += wartosc;
            }
            if (trafione[1] > 0)
            {
                wartosc = trafione[1] * rnd.Next(100, 301);
                Console.WriteLine("4 Trafienia: {0} raz(y) + {1}zł", trafione[1], wartosc);
                wygrana += wartosc;
            }
            if (trafione[2] > 0)
            {
                wartosc = trafione[2] * rnd.Next(4000, 8001);
                Console.WriteLine("5 Trafienia: {0} raz(y) + {1}zł", trafione[2], wartosc);
                wygrana += wartosc;
            }
            if (trafione[3] > 0)
            {
                wartosc = (trafione[3] * kumulacja) / (trafione[3] + rnd.Next(0, 5));//sprawdzic te warunki
                Console.WriteLine("6 Trafienia: {0} raz(y) + {1}zł", trafione[3], wartosc);
                wygrana += wartosc;
            }
            return wygrana;
        }

        private static int[] SprawdzKupon(List<int[]> kupon, int[] wylosowane)
        {
            int[] wygrane = new int[4];
            int i = 0;
            Console.WriteLine("\n\nTWÓJ KUPON: ");
            foreach (int[] los in kupon)
            {
                i++;
                Console.Write(i + ": ");
                int trafien = 0;
                foreach (int liczba in los)
                {
                    if (wylosowane.Contains(liczba))
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write(liczba + ", ");
                        Console.ResetColor();
                        trafien++;
                    }
                    else
                    {
                        Console.Write(liczba + ", ");
                    }
                }
                switch (trafien)
                {
                    case 3:
                        wygrane[0]++;
                        break;
                    case 4:
                        wygrane[1]++;
                        break;
                    case 5:
                        wygrane[2]++;
                        break;
                    case 6:
                        wygrane[3]++;
                        break;
                }
                Console.WriteLine(" - Trafiono {0}/6", trafien);
            }
            return wygrane;
        }

        private static int[] PostawLos()
        {
            int[] liczby = new int[6];
            int liczba = -1;
            for (int i = 0; i < liczby.Length; i++)
            {
                liczba = -1;
                Console.Clear();
                Console.WriteLine("Postawione liczby: ");
                foreach (int l in liczby)
                {
                    if (l > 0)
                    {
                        Console.Write(l + ", ");
                    }
                }
                Console.WriteLine("\n\nWybierz liczbę od 1 do 49:");
                Console.Write("{0}/6: ", i + 1);
                bool prawidlowa = int.TryParse(Console.ReadLine(), out liczba);
                if (prawidlowa && liczba >= 1 && liczba <= 49 && !liczby.Contains(liczba))
                {
                    liczby[i] = liczba;
                }
                else
                {
                    Console.WriteLine("Niestety błędna liczba.");
                    i--;
                    Console.WriteLine("Wciśnij dowolny przycisk, aby kontynuować");
                    Console.ReadKey();
                }
            }
            Array.Sort(liczby);
            return liczby;
        }

        private static void WyswietlKupon(List<int[]> kupon)
        {
            if (kupon.Count == 0)
            {
                Console.WriteLine("Nie postawiłeś jeszcze żadnych losów.");
            }
            else
            {
                int i = 0;
                Console.WriteLine("\nTWÓJ KUPON: ");
                foreach (int[] los in kupon)
                {
                    i++;
                    Console.Write(i + ": ");
                    foreach (int liczba in los)
                    {
                        Console.Write(liczba + ", ");
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}
