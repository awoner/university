using ArchitectureLab1;
using ArchitectureLab1.Entities;
using ArchitectureLab1.Patterns.Commands;
using NUnit.Framework;
using System;

namespace ArchitectureLab1Tests
{
    [TestFixture]
    public class ControllerTest
    {
        [Test]
        public void CallProxy()
        {
            //arrange
            var controller = new Controller(new View());

            //assert
            Assert.DoesNotThrow(() => controller.Execute<CallProxyCommand>(new Notebook()));
        }

        [Test]
        public void CallMethodsTest()
        {
            //arrange
            var controller = new Controller(new View());

            //assert
            Assert.DoesNotThrow(() => controller.Execute<InvokeCommand>(new Notebook()));
        }

        [Test]
        public void ShowConstructorsTest()
        {
            //arrange
            var controller = new Controller(new View());

            //assert
            Assert.DoesNotThrow(() => controller.Execute<ShowConstructorsCommand>(new Notebook()));
        }

        [Test]
        public void ShowModifiersTest()
        {
            //arrange
            var controller = new Controller(new View());

            //assert
            Assert.DoesNotThrow(() => controller.Execute<ShowModifiersCommand>(new Notebook()));
        }
    }
}
