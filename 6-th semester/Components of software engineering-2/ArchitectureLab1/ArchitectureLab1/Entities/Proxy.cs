using ArchitectureLab1.Interfaces;
using System;

namespace ArchitectureLab1.Entities
{
    public class Proxy : IProduct
    {
        public IProduct Product { get; set; }
        public decimal Price { get => Product.Price; set => throw new InvalidOperationException("Not allowed!"); }

        public Proxy(IProduct product)
        {
            Product = product;
        }

        public string Invoke()
        {
            throw new InvalidOperationException("Not allowed!");
        }
    }
}
