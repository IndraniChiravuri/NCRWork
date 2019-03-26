using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Methods
{
    class Program
    {

        public int add(int n1, int n2, out int sum)
        {
            sum = n1 + n2 + n2;
            return n1 + n2;
        }

        public int AddSum(int n1, int n2, params int[] valueSet)
        {
            if (valueSet != null)
            {
                int sum = 0;
                for (int i = 0; i < valueSet.Length; i++)
                    sum += valueSet[i];
                foreach(int x in valueSet) {
                    sum += x;
                } 
                return sum; 
            }
            return n1 + n2;
        }

        public int defaultParam(int x, int y = -1, int z = -2)
        {
            return x + y + z;
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            int n1 = 20;
            int n2 = 30;
            int sum1;
            int sum2 = p.add(n1, n2, out sum1);
            Console.WriteLine("Sum1: " + sum1);
            Console.WriteLine("Sum2: " + sum2);
            Console.WriteLine(p.AddSum(n1, n2, 1,2,3));
            Console.WriteLine("Default Param: " + p.defaultParam(5, z:0));
            Console.Read();
        }
    }
}
