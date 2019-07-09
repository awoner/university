using ArchitectureLab1.Attributes;
using ArchitectureLab1.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArchitectureLab1.Entities
{
    public class Diary : IDiary
    {
        public string Plan { get; set; }
        public DateTime Date { get; set; }
        public decimal Price { get; set; }

        public Diary()
        {
            Plan = "None";
            Date = DateTime.Now;
            Price = 0;
        }

        [ReflectionOutputable]
        public override string ToString()
        {
            return $"Plan: {Plan}\n" +
                $"Date: {Date}\n" + 
                $"Price: {Price}\n";
        }

        public bool Equals(Diary other)
        {
            return Plan == other.Plan &&
                Date == other.Date;
        }

        public string Invoke()
        {
            var attributedMethods =
                GetType()
                .GetMethods()
                .Where(methodInfo => Attribute.IsDefined(methodInfo, typeof(ReflectionOutputableAttribute)))
                .ToList();

            string str = string.Empty;

            foreach (var method in attributedMethods)
            {
                str += $"\n\ncalling {method.ReturnType.Name} {method.Name}() ...\n";
                str += method.Invoke(this, method.GetParameters()).ToString() + '\n';
            }

            return str;
        }
    }
}
