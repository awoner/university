using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArchitectureLab1.Interfaces
{
    public interface IProduct
    {
        decimal Price { get; set; }
        string Invoke();
    }
}
