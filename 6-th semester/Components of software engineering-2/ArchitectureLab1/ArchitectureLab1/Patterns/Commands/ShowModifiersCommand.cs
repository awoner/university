using ArchitectureLab1.Extensions;
using ArchitectureLab1.Interfaces;

namespace ArchitectureLab1.Patterns.Commands
{
    public sealed class ShowModifiersCommand : ICommand
    {
        private readonly IProduct product;

        public ShowModifiersCommand(IProduct product)
        {
            this.product = product;
        }

        public string Execute()
        {
            return product.GetType().GetModifiersString() + '\n';
        }
    }
}
