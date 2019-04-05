using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DPDemo
{
    abstract class Product
    {

    }
    class ConcreteProduct1: Product
    {

    }

    class ConcreteProduct2 : Product
    {

    }
    abstract class Creator
    {
        public abstract Product FactoryMethod();
    }

    class ConcreteCreator1 : Creator
    {
        public override Product FactoryMethod()
        {
            return new ConcreteProduct1();
           // throw new NotImplementedException();
        }
    }

    class ConcreteCreator2 : Creator
    {
        public override Product FactoryMethod()
        {
            return new ConcreteProduct2();
           // throw new NotImplementedException();
        }
    }
    class FactoryMethod
    {
    }
}
