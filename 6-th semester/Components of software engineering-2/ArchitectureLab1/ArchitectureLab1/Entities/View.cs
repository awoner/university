using ArchitectureLab1.Interfaces;
using System;

namespace ArchitectureLab1.Entities
{
    public class View : IView
    {
        public virtual void WriteLine(string str)
        {
            Console.WriteLine(str);
        }

        public virtual void WriteLine()
        {
            Console.WriteLine();
        }

        public virtual void Read()
        {
            Console.Read();
        }
    }
}
