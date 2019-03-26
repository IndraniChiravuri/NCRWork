using InterfaceDemp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterfaceDemp
{
    interface MyInterface
    {
        void print();
    }

    interface MyInterface2
    {
        void print();
    }
    class Program : MyInterface, MyInterface2
    {
        static void Main(string[] args)
        {
            Program p = new Program();
            // p.print() -- NOT POSSIBLE
            ((MyInterface2)(p)).print();
            ((MyInterface)p).print();

            Console.Read();
        }

        void MyInterface.print()
        {
            Console.WriteLine("Class Print - 1");
        }

        void MyInterface2.print()
        {
            Console.WriteLine("Class Print - 2");
        }
    }
}
