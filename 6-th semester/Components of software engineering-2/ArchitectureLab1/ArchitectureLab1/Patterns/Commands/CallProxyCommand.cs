using ArchitectureLab1.Entities;
using ArchitectureLab1.Interfaces;
using System;

namespace ArchitectureLab1.Patterns.Commands
{
    public sealed class CallProxyCommand : ICommand
    {
        private IProduct product;

        public CallProxyCommand(IProduct product)
        {
            this.product = product;
        }

        public string Execute()
        {
            var proxy = new Proxy(product);
            string str = string.Empty;
            try
            {
                str += $"{ proxy.GetType().Name } method get:\t{ proxy.Price }\n";
                str += $"{ proxy.GetType().Name } method set:\t\n";
                proxy.Price = 113.50M;
            }
            catch (Exception ex)
            {
                str += ex.Message + '\n';
            }

            return str;
        }
    }
}
