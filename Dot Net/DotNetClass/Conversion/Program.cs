using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conversion
{
    class Program
    {
        string name;

       /* public Program() { }

        public Program(string strName) {
            name = strName;
        } */

        string getName()
        {
            return name;
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            //Program p1 = new Program("Chandler Bing");
            int x = 21;
            float y = 21.5f;
            Console.WriteLine("Before Conversion: ");
            Console.WriteLine(x);
            Console.WriteLine(y);
            // IMPLICIT CONVERSION
            y = x;
            Console.WriteLine("Implicit Converison: ");
            Console.WriteLine(x);
            Console.WriteLine(y);
            p.name = "Joey Tribbianne";
            Console.WriteLine("Name: " + p.getName());
            //Console.WriteLine("Name: " + p1.getName());
            Console.Read();
        }
    }
}
