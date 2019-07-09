using ArchitectureLab1.Entities;
using ArchitectureLab1.Interfaces;
using NUnit.Framework;
using System;

namespace ArchitectureLab1Tests
{
    [TestFixture]
    public class ProxyTest
    {
        [Test]
        public void GetPriceTest()
        {
            //arrange
            var proxy = new Proxy(
                new Notebook()
                {
                    Name = "Oleksiy",
                    Surname = "Artamonov",
                    Patronymic = "Yuriyovich",
                    MobileNumber = "+380988423041",
                    BirthdayDate = new DateTime(1999, 6, 7),
                    Price = 12.02M
                });

            decimal expected = 12.02M;

            //act
            decimal actual = proxy.Price;

            //assert
            Assert.AreEqual(expected, actual);
        }

        [Test]
        public void GetProductTest()
        {
            //arrange
            var proxy = new Proxy(
                new Notebook()
                {
                    Name = "Oleksiy",
                    Surname = "Artamonov",
                    Patronymic = "Yuriyovich",
                    MobileNumber = "+380988423041",
                    BirthdayDate = new DateTime(1999, 6, 7)
                });

            IProduct expected = new Notebook()
            {
                Name = "Oleksiy",
                Surname = "Artamonov",
                Patronymic = "Yuriyovich",
                MobileNumber = "+380988423041",
                BirthdayDate = new DateTime(1999, 6, 7)
            };

            //act
            IProduct actual = proxy.Product;

            //assert
            Assert.AreEqual(expected, actual);
        }

        [Test]
        public void SetPriceTest()
        {
            //arrange
             var proxy = new Proxy(new Notebook());

            //assert
            Assert.Throws<InvalidOperationException>(delegate { proxy.Price = 143; });
        }
    }
}
