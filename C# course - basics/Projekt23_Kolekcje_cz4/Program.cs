using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Projekt23_Kolekcje_cz4
{
    class Program
    {
        static void Main(string[] args)
        {
            //Wszystku tu jest generyczne

            //FIFO
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(11);
            queue.Enqueue(22);
            queue.Enqueue(123);
            Console.WriteLine(queue.Peek());
            Console.WriteLine(queue.Dequeue());
            Console.WriteLine(queue.Peek());


            //LIFO
            Stack<int> stack = new Stack<int>();
            stack.Push(1111);
            stack.Push(1131);
            stack.Push(1121);
            Console.WriteLine(stack.Peek());
            Console.WriteLine(stack.Pop());
            Console.WriteLine(stack.Peek());

            Console.ReadKey();
        }
    }
}
