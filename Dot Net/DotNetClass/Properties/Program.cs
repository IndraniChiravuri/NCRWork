using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Properties
{
    class Time
    {
        private int secs;
        public int Secs
        {
            get
            {
                return secs;
            }

            set
            {
                secs = value;
            }
        }

        private double hours;
        public double Hours{
            get
            {
                return hours;
            }

            set
            {
                hours = value;
            }
        }

        public int MyProperty {
            get; //{ return MyProperty; }
            set; //{ MyProperty = value;  }
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Time t = new Time();
            t.MyProperty = 20;
            int p = t.MyProperty;
            Console.WriteLine(p);
            t.Hours = 24;
            Console.WriteLine(t.Hours);
            Console.Read();
        }
    }
}
