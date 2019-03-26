using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccessSepcifierDemo1
{
    partial class Class1
    {
        public void printPartial()
        {
            Console.WriteLine("Pint Partial X: " + x);
        }
        partial void method()
        {
            Console.WriteLine("Partial Method");
            throw new NotImplementedException();
        }
    }
}
