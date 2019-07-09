using ArchitectureLab1.Interfaces;
using ArchitectureLab1.Patterns.Commands;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArchitectureLab1.Patterns.SimpleFactory
{
    internal sealed class CommandFactory
    {
        private IProduct product;
        private static CommandFactory instance;

        private CommandFactory(IProduct product)
        {
            this.product = product;
        }

        public static CommandFactory Init(IProduct product)
        {
            if (instance is null)
            {
                instance = new CommandFactory(product);
            }

            return instance;
        }


        public ICommand Create<T>() where T : ICommand
        {
            var @switch = new Dictionary<Type, Func<ICommand>>
            {
                { typeof(InvokeCommand), () => new InvokeCommand(product) },
                { typeof(CallProxyCommand), () => new CallProxyCommand(product) },
                { typeof(ShowConstructorsCommand), () => new ShowConstructorsCommand(product) },
                { typeof(ShowModifiersCommand), () => new ShowModifiersCommand(product) },
                { typeof(ShowTypeInfoCommand), () => new ShowTypeInfoCommand(product) }
            };

            return @switch[typeof(T)]();
        }
    }
}
