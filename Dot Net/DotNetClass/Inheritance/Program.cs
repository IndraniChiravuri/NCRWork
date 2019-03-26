using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    class Employee
    {
        internal string firstName;
        internal string lastName;
        internal string email;

         internal virtual void printFullName()
        {
            Console.WriteLine(firstName + " " + lastName);
        }
    }

    class FullTimeEmployee : Employee
    {
        internal int annualSalary;

        override
        internal void printFullName()
        {
            Console.WriteLine("{0} {1} -- Full Time", firstName, lastName);
        }
    }

    class ContractEmployee : Employee
    {
        internal int monthlySalary;
        /* this is not method over riding , we just want to hide the base class method so that we could find the type of employee
         * to do that we need to hide the base class method which will be achieved using new keyword
         * new internal void printFullName()
         {
             Console.WriteLine("{0} {1} -- Contract", firstName, lastName);
         } */

        override
        internal void printFullName()
        {
            Console.WriteLine("{0} {1} -- Contract", firstName, lastName);
        } 
    }
    class Program
    {
        static void Main(string[] args)
        {
            Employee e = new Employee();
            e.firstName = "Chanandolor";
            e.lastName = "Bong";
            e.printFullName();
            e = new FullTimeEmployee();
            e.firstName = "Chanandolor";
            e.lastName = "Bong";
            e.printFullName();
            e = new ContractEmployee();
            e.firstName = "Chanandolor";
            e.lastName = "Bong";
            e.printFullName();

            ContractEmployee c = new ContractEmployee();
            c.firstName = "Chanandolor";
            c.lastName = "Bong";
            c.printFullName();
            Console.Read();
        }
    }
}
