using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IndexersDemo
{
    class Employee
    {
        public int empId;
        public string name;


        public Employee(int v1, string v2)
        {
            this.empId = v1;
            this.name = v2;
        }
    }
    class Program
    {
        System.Collections.Generic.List<Employee> list = new System.Collections.Generic.List<Employee>();
        Program()
        {
            list.Add(new Employee(22, "Bee"));
            list.Add(new Employee(21, "Mr. Poojari"));
            list.Add(new Employee(9, "Puppy"));
            list.Add(new Employee(10, "Cry Baby"));
            list.Add(new Employee(10, "Daddojanam"));
            list.Add(new Employee(8, "Honey"));
            list.Add(new Employee(2, "Dermicool"));
        }

        public string this [int id]
        {
            get
            {
                return list.FirstOrDefault(emp => emp.empId == id).name;
            }
            set
            {
                list.FirstOrDefault(emp => emp.empId == id).name = value;
            }
    }
        static void Main(string[] args)
        {
            Program p = new Program();
            //int index = Console.Read();
            Console.WriteLine(p[9]);

            Console.Read();
        }
    }
}
