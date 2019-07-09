using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArchitectureLab1.Entities
{
    public class Creator
    {
        public virtual Notebook CreateNotebook()
        {
            return new Notebook("Ivan", "Belanov", "Viktorovich", "+38067715109", new DateTime(2000, 11, 25));
        }

        public virtual Proxy CreateProxy()
        {
            return new Proxy(CreateNotebook());
        }
    }
}
