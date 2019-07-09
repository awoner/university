using ArchitectureLab1.Extensions;
using ArchitectureLab1.Interfaces;

namespace ArchitectureLab1.Patterns.Commands
{
    public sealed class ShowConstructorsCommand : ICommand
    {
        private readonly IProduct product;

        public ShowConstructorsCommand(IProduct product)
        {
            this.product = product;
        }

        public string Execute()
        {
            return "Constructors:\n" + product.GetType().GetConstructorsString() + '\n';
        }
    }
}
