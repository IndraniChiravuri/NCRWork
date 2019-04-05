using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DPDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Creator[] creators = new Creator[2];
            creators[0] = new ConcreteCreator1();
            creators[1] = new ConcreteCreator2();

            foreach(Creator c in creators)
            {
                Product p = c.FactoryMethod();
                Console.WriteLine(p.ToString());
                Console.WriteLine(p.GetType().Name);
            }
            Console.Read();
        }
    }
}
