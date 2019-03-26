using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LINQDemo
{
    class Employee
    {
        int id;
        string name;
        string gender;

        public Employee(int v1, string v2, string v3="")
        {
            this.id = v1;
            this.name = v2;
            this.gender = v3;
        }

        public Employee()
        {
        }

        public int Id
        {
            get
            {
                return id;
            }

            set
            {
                id = value;
            }
        }

        public string Name
        {
            get
            {
                return name;
            }

            set
            {
                name = value;
            }
        }

        public string Gender
        {
            get
            {
                return gender;
            }

            set
            {
                gender = value;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Program p = new Program();
            p.LinqIntroMethod();
            p.deferredExecution();
            p.aggregateMethod();
            p.projectionOperator();
            p.partitioningMethod();
            p.elementMethod();
            p.quantifier();
            Console.Read();
        }

        private void quantifier()
        {
            Console.WriteLine("=====QUANTIFIER=====");
            List<int> list = new List<int>() { 1, 2, 3, 6, 7 };
            if (list.All(x => x < 8))
                Console.WriteLine("All elements are less than 8");
            if (!list.Contains(5))
                Console.WriteLine("List does not contain 5");
            if (list.Any(x => x > 6))
                Console.WriteLine("Atleast one element is greater than 6");
        }

        private void elementMethod()
        {
            List<string> list = new List<string>()
            {
                "Joey", "Chandler", "Ross", "Rachel", "Monica", "Phoebe"
            };
            Console.WriteLine("=====ELEMENT METHOD=====");
            //THROWS EX IF LIST IS EMPTY
            Console.WriteLine("First Ele: " + list.First());
            // DOES NOT THROWS EX IF THE LIST IS EMPTY
            Console.WriteLine("First Ele: " + list.FirstOrDefault());
            Console.WriteLine("Ele At 4: " + list.ElementAt(4));
            // DOES NOT THROWS ANY EXCEPTION
            Console.WriteLine("Ele At 6: " + list.ElementAtOrDefault(6));
            // USED WHEN THERE IS ONLY ONE ELEMENT IN LIST THROWS AND EX OTHER WAYS
            //Console.WriteLine("First Ele: " + list.Single());
            //Console.WriteLine("First Ele: " + list.SingleOrDefault());
        }

        private void partitioningMethod()
        {
            List<string> list = new List<string>()
            {
                "Joey", "Chandler", "Ross", "Rachel", "Monica", "Phoebe"
            };
        }

        private void projectionOperator()
        {
            Console.WriteLine("=====PROJECTION AND RESTRICTION=====");
            List<Employee> list = new List<Employee>()
            {
                new Employee(21, "Chandler", "Male"),
                new Employee(22, "Monica", "Female"),
                new Employee(23, "Joey", "Male")
            };
            //Employee emp = new Employee();
            var res = list.Where (emp => emp.Gender == "Male" ).Select (emp => new { Id = emp.Id, Name = emp.Name });
            foreach(var emp in res)
            {
                Console.WriteLine(emp.Name);
            }
            var groupSet = list.GroupBy(emp => emp.Gender);
            foreach (var group in groupSet)
                Console.WriteLine("{0} {1}", group.Key, group.Count());

        }

        private void aggregateMethod()
        {
            Console.WriteLine("====AGGREGATE METHOD====");
            List<int> numbers = new List<int> { -1, 1, 2, 3, 4, 5, 6 };
            Console.WriteLine("Min: " + numbers.Min());
            Console.WriteLine("Max: " + numbers.Max());
            Console.WriteLine("Sum: " + numbers.Sum());
            Console.WriteLine("Count: " + numbers.Count());
            Console.WriteLine("Avg: " + numbers.Average());
            Console.WriteLine("Aggregate: " + numbers.Aggregate((a,b) => a * b));
        }

        private void deferredExecution()
        {
            List<int> numbers = new List<int> { 1, 2, 3, 4, 5, 6 };
            var res = from num in numbers
                      where num % 2 == 0
                      select num;
            numbers.Add(7);
            numbers.Add(8);
            Console.WriteLine("====EXECUTION====");
            foreach (var num in res)
                Console.WriteLine(num);
            // LINQ EXECUTES ONLY WHEN WE ARE USING IT, IN THIS CASE IN FOREACH LOOP
        }

        private void LinqIntroMethod()
        {
            string path = @"C:\Windows";
            DirectoryInfo info = new DirectoryInfo(path);
            FileInfo[] files = info.GetFiles();
           // Array.Sort(files, new FileCompareTest());
            Array.Reverse(files);

            List<FileInfo> result = new List<FileInfo>();

            for (int i = 0; i < 5; i++)
            {
                result.Add(files[i]);
            }
            // QUERY SYNTAX
            var res1 = (from file in files
                        orderby file.Length descending
                        select file).Take(5);
            Console.WriteLine("====QUERY SYNTAX====");
            foreach (var res in res1)
                Console.WriteLine(res);
            // METHOD SYNTAX
            var res2 = files.OrderByDescending(file => file.Length).Take(5);
            Console.WriteLine("====METHOS SYNTAX====");
            foreach (var res in res2)
                Console.WriteLine(res);
        }

        
    }
}
