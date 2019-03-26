using alias_name = AccessSepcifierDemo1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartialClass
{
    partial class PartialClassDemo
    {
        int x;
        public void printX()
        {
            Console.WriteLine("X: " + x);
        }
    }

    partial class PartialClassDemo
    {
        int y;
        public void printY()
        {
            Console.WriteLine("X: " + x);
            Console.WriteLine("Y: " + y);
        }
    }
    class Program
    {
        /*static void Main(string[] args)
        {
            PartialClassDemo p = new PartialClassDemo();
            //p.printX();
            p.printY();

            Console.Read(); 
        } */
        static void Main(string[] args)
        {
            alias_name.Class1 c = new alias_name.Class1();
            c.printPartial();
            c.printX();
            //c.method();
            Console.Read();
        }
    }
}
