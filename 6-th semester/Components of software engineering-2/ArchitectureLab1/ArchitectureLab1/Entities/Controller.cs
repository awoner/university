using ArchitectureLab1.Interfaces;
using ArchitectureLab1.Patterns.SimpleFactory;
using ArchitectureLab1.Patterns.Commands;

namespace ArchitectureLab1.Entities
{
    public class Controller
    {
        private readonly IView view;
        //private ICommand command;

        public Controller(IView view)
        {
            this.view = view;
        }

        public virtual void Execute<T>(IProduct product) where T : ICommand
        {
            var factory = CommandFactory.Init(product);
            var command = factory.Create<T>();

            view.WriteLine(command.Execute());
        }

        //public void CallMethods(INotebook notebook)
        //{
        //    var attributedMethods = notebook
        //        .GetType()
        //        .GetMethods()
        //        .Where(methodInfo => Attribute.IsDefined(methodInfo, typeof(ReflectionOutputableAttribute)))
        //        .ToList();

        //    foreach (var method in attributedMethods)
        //    {
        //        view.WriteLine($"\n\ncalling {method.ReturnType.Name} {method.Name}() ...\n");
        //        view.WriteLine((method.Invoke(notebook, method.GetParameters())).ToString()
        //            + (method.Name.Equals("GetDaysBeforeBirthday") ? " days before birthday." : ""));
        //    }
        //}

        ///// <summary>
        ///// Call all methods of Notebook type thats has ReflectionOutputable attribute via reflection
        ///// </summary>
        //public void CallMethods()
        //{
        //    CallMethods(creator.CreateNotebook());
        //}
    }
}