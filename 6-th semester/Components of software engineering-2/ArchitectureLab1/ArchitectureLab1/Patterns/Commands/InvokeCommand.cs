using ArchitectureLab1.Interfaces;

namespace ArchitectureLab1.Patterns.Commands
{
    public sealed class InvokeCommand : ICommand
    {
        private IProduct product;

        public InvokeCommand(IProduct product)
        {
            this.product = product;
        }

        public string Execute()
        {
            return product.Invoke();
        }
    }
}
