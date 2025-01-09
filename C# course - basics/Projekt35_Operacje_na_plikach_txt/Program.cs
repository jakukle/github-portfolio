using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt35_Operacje_na_plikach_txt
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"plik.txt";
            StreamWriter sw;
            int j = 1;
            while (j <= 15)
                {
                    if (!File.Exists(path))
                {
                    sw = File.CreateText(path);
                    Console.WriteLine("Plik został utworzony");
                }
                else
                {
                    sw = new StreamWriter(path, true);
                    Console.WriteLine("Plik został otwarty");
                }
            
                Console.Write("Podaj tekst: ");
                string tekst = Console.ReadLine();
                sw.WriteLine(tekst);
                sw.Close();

                StreamReader sr = File.OpenText(path);
                string s = "";
                int i = 1;
                Console.WriteLine("\nZAWARTOŚĆ PLIKU: ");
                while ((s = sr.ReadLine()) != null)
                {
                    Console.WriteLine(i++ + ". " + s);
                }
                sr.Close();

                Console.WriteLine();

                i = 1;
                sr = File.OpenText(path);
            Label: s = sr.ReadLine();
                if (s != null)
                {
                    Console.WriteLine(i++ + ". " + s);
                    goto Label;
                }
                sr.Close();

                Console.WriteLine();

                i = 1;
                sr = File.OpenText(path);
                foreach (string line in File.ReadLines(path))
                {
                    Console.WriteLine(i++ + ". " + line);
                }
                sr.Close();

                Console.WriteLine();
                j++;
            }
            //Console.WriteLine("Wcisnij przycisk aby skasowac plik");
            //Console.ReadKey();
            //File.Delete(path);
        }
    }
}
