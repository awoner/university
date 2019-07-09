using ArchitectureLab1.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArchitectureLab1.Patterns.Prototype
{
    internal interface IPrototype
    {
        IProduct Clone();
    }
}
