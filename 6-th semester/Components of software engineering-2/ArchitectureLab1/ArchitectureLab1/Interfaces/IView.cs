using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArchitectureLab1.Interfaces
{
    public interface IView
    {
        void WriteLine(string str);
        void WriteLine();
        void Read();
    }
}
