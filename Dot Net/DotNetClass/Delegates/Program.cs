using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegates
{
    public delegate void DelegateHelper(string s);
    class Program
    {
        //public static object DelegateHelper { get; private set; }

        static void Main(string[] args)
        {
            DelegateHelper helper = new DelegateHelper(greet);
            helper("Hey!");
            Console.Read();
        }

        private static void greet(string s)
        {
            Console.WriteLine(s);
            
        }
    }
}
