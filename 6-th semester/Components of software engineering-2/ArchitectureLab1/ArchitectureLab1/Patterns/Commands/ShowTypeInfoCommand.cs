using ArchitectureLab1.Extensions;
using ArchitectureLab1.Interfaces;
using System;

namespace ArchitectureLab1.Patterns.Commands
{
    /// <summary>
    /// Show all info about type by reflection
    /// </summary>
    public sealed class ShowTypeInfoCommand : ICommand
    {
        private IProduct product;

        public ShowTypeInfoCommand(IProduct product)
        {
            this.product = product;
        }

        public string Execute()
        {
            string str = string.Empty;

            str += product.GetType().GetModifiersString() + '\n';
            str += "Constructors:\n";
            str += product.GetType().GetConstructorsString() + '\n';
            str += product.Invoke();

            str += new string('-', 70) + "\n";

            return str;
        }
    }
}
