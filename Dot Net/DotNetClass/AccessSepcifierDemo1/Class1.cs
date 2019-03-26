using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AccessSepcifierDemo1
{
    public partial class Class1
    {
        int x;

        public void printX()
        {
            Console.WriteLine("Print X : " + x);
            method();
        }

        partial void method();
    }
}
