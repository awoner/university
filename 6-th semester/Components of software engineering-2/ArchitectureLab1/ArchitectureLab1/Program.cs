using ArchitectureLab1.Entities;
using ArchitectureLab1.Patterns.Commands;
using System;

namespace ArchitectureLab1
{
    public class Program
    {
        static void Main(string[] args)
        {
            var controller = new Controller(new View());


            Notebook notebook = new Notebook()
            {
                Name = "Alex",
                Surname = "Artamonov",
                Patronymic = "Yuriyovich",
                MobileNumber = "+380988423041",
                BirthdayDate = new DateTime(1999, 6, 7)
            };

            Console.WriteLine(notebook.ToString());

            controller.Execute<ShowTypeInfoCommand>(notebook);
            controller.Execute<InvokeCommand>(notebook);


            Diary diary = new Diary();

            controller.Execute<ShowTypeInfoCommand>(diary);
            controller.Execute<InvokeCommand>(diary);
            controller.Execute<CallProxyCommand>(diary);
        }
    }
}