using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExceptionHandling
{
    class ExceptionDemo
    {
        public void readFile()
        {
            StreamReader sr = null;
            try
            {
                sr = new StreamReader(@"C:\Users\admin\Desktop\blah.txt");
                Console.WriteLine(sr.ReadToEnd());
            }
            catch (Exception e)
            {
                Console.WriteLine("File Not Found!");
            }
            finally
            {
                sr.Close();
            }
        }
    }

    class Divide
    {
        /* int n1;
         int n2;
         public void divide()
         {
             try
             {
                 n1 = Convert.ToInt32(Console.ReadLine());
                 n2 = Convert.ToInt32(Console.ReadLine());
                 if (n2 == 0)
                     throw new DivideByZeroException();
             } catch(Exception e)
             {
                 Console.WriteLine("Denominator Cannot be Zero");
             }
         } */
        string n1;
        string n2;
        public void divide()
        {
            try
            {
                n1 = Console.ReadLine();
                n2 = Console.ReadLine();
                float res = Convert.ToInt32(n1) / Convert.ToInt32(n2);
                Console.WriteLine("Res: " + res);
            } catch (FormatException formatEx)
            {
                Console.WriteLine("Format");
            } catch (DivideByZeroException ex)
            {
                Console.WriteLine("Divide by zero");
            } catch(OverflowException overflow)
            {
                Console.WriteLine("Overflow");
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            ExceptionDemo e = new ExceptionDemo();
            //e.readFile();
            Divide d = new Divide();
            d.divide();
            int res;
            if(int.TryParse("2", out  res)) { // returns true if the convresion is true
                Console.WriteLine(res);
            }
            Console.Read();
        }
    }
}
