using ArchitectureLab1.Entities;
using ArchitectureLab1.Patterns.Commands;
using Moq;
using NUnit.Framework;
using System;

namespace ArchitectureLab1MockTests
{
    [TestFixture]
    public class MockTest
    {

        public Mock<Creator> CreatorMock { get; } = new Mock<Creator>();
        public Mock<View> ViewMock { get; } = new Mock<View>();

        [Test]
        public void TestCallMethodsWithInvokeAttribute()
        {
            var notebookMock = new Mock<Notebook>();
            notebookMock.Setup(p => p.Invoke()).Returns(It.IsAny<string>);

            var controller = new Controller(ViewMock.Object);
            controller.Execute<InvokeCommand>(notebookMock.Object);

            ViewMock.Verify(i => i.WriteLine(It.IsAny<string>()), Times.Once);
            notebookMock.Verify(n => n.Invoke(), Times.Once);
        }

        [Test]
        public void TestCallProxySetter()
        {
            var creatorMock = CreatorMock;
            var notebook = creatorMock.Object.CreateNotebook();

            creatorMock.Setup(i => i.CreateProxy()).Returns(new Proxy(notebook));

            var controllerMock = new Mock<Controller>();
            controllerMock.Setup(i => i.Execute<CallProxyCommand>(notebook)).Throws(new InvalidOperationException());

            var controller = new Controller(ViewMock.Object);
           
            
            controllerMock.Verify();
            creatorMock.Verify(i => i.CreateProxy(), Times.Never);
            ViewMock.Verify(v => v.WriteLine(It.IsAny<string>()), Times.Once);
        }

        [Test]
        public void TestCreateProxyWithNotebookInstance()
        {
            var creatorMock = CreatorMock;
            creatorMock.Setup(i => i.CreateNotebook()).Returns(new Creator().CreateNotebook());

            var proxy = creatorMock.Object.CreateProxy();

            creatorMock.Verify(i => i.CreateProxy(), Times.Once);
        }

        [Test]
        public void TestShowModifiers()
        {
            var controller = new Controller(ViewMock.Object);
            controller.Execute<ShowModifiersCommand>(CreatorMock.Object.CreateNotebook());

            ViewMock.Verify(v => v.WriteLine(It.IsAny<string>()), Times.Exactly(3));
        }

        [Test]
        public void TestShowConstructor()
        {
            var controller = new Controller(ViewMock.Object);
            controller.Execute<ShowConstructorsCommand>(CreatorMock.Object.CreateNotebook());

            ViewMock.Verify(v => v.WriteLine(It.IsAny<string>()), Times.Exactly(2));
        }
    }
}
