using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CollectionsDem
{

    class DictDemo
    {
        Dictionary<int, string> person = new Dictionary<int, string>();

        public void addValue(int key, string value) {
            person.Add(key, value);
        }

        public void display()
        {
            foreach(KeyValuePair<int, string> p in person)
            {
                Console.WriteLine("Id: {0} Name: {1}", p.Key, p.Value);
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            DictDemo d = new DictDemo();
            d.addValue(21, "Joey");
            d.addValue(22, "Chan");
            d.addValue(2, "Mon");
            d.addValue(10, "Ross");
            d.addValue(9, "Phoebe");
            d.addValue(8, "Rachel");
            Console.WriteLine(" ------- ");
            d.display();
            Program p = new Program();
            p.implementSort();
            Console.Read();
        }

        private void implementSort()
        {
            List<int> l = new List<int>()
            {
                10, 21, 2, 8, 22, 9
            };
            foreach(int x in l) 
                Console.WriteLine(x);
            Console.WriteLine(" ------- ");
            l.Sort();
            foreach (int x in l)
                Console.WriteLine(x);
        }
        
    }
}
