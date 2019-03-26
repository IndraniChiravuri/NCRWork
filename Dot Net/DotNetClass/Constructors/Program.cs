using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Constructors
{
    class Base
    {
        public Base() {
            Console.WriteLine("Base Default");
        }
        public Base(string a) {
            Console.WriteLine("Base Parameterizex");
            Console.WriteLine(a);
        }
    }
    class Derived : Base
    {
        public Derived() : base("Base PAram") {
            Console.WriteLine("Derived Default");
        }
        public Derived(string str): base(str)
        {
            Console.WriteLine("Child Param");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Base b = new Base();
            Derived d = new Derived();
            Derived d1 = new Derived("Hey!");
            Console.Read();
        }
    }
}
