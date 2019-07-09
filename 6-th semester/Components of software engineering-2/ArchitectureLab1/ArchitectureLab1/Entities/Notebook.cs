using ArchitectureLab1.Attributes;
using ArchitectureLab1.Interfaces;
using ArchitectureLab1.Patterns.Prototype;
using System;
using System.Linq;

namespace ArchitectureLab1.Entities
{
    public class Notebook : Date, INotebook, IEquatable<Notebook>, IPrototype
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Patronymic { get; set; }
        public string MobileNumber { get; set; }
        public decimal Price { get; set; }

        public Notebook()
        {
            Name = Surname = Patronymic = MobileNumber = "None";
            Price = 0;
            BirthdayDate = DateTime.Now;
        }

        public Notebook(string name, string surname, string patronymic, string mobileNumber, DateTime dateTime)
        {
            Name = name;
            Surname = surname;
            Patronymic = patronymic;
            MobileNumber = mobileNumber;
            BirthdayDate = dateTime;
        }

        public Notebook(string name, string surname, string patronymic, string mobileNumber, string dateTime)
        {
            Name = name;
            Surname = surname;
            Patronymic = patronymic;
            MobileNumber = mobileNumber;

            BirthdayDate = DateTime.TryParse(dateTime, out DateTime date) ? date : throw new Exception("Incorrect string format of date!");
        }

        [ReflectionOutputable]
        public override string ToString()
        {
            return $"Name: {Name}\n" +
                $"Surname: {Surname}\n" +
                $"Patronymic: {Patronymic}\n" +
                $"Mobile number: {MobileNumber}\n" +
                $"Birthday date: {base.ToString()}\n" +
                $"Price: {Price}\n";
        }

        [ReflectionOutputable]
        public uint GetDaysBeforeBirthday()
        {
            var birthday = BirthdayDate.AddYears(DateTime.Now.Year - BirthdayDate.Year);
            return (uint)(birthday - DateTime.Now).TotalDays + 1;
        }

        public virtual string Invoke()
        {
            var attributedMethods = 
                GetType()
                .GetMethods()
                .Where(methodInfo => Attribute.IsDefined(methodInfo, typeof(ReflectionOutputableAttribute)))
                .ToList();

            string str = string.Empty;

            foreach (var method in attributedMethods)
            {
                str += $"\n\ncalling {method.ReturnType.Name} {method.Name}() ...\n";
                str += (method.Invoke(this, method.GetParameters())).ToString() + '\n'
                    + (method.Name.Equals("GetDaysBeforeBirthday") ? " days before birthday." : "");
            }

            return str += '\n';
        }

        public bool Equals(Notebook other)
        {
            return Name == other.Name &&
                Surname == other.Surname &&
                Patronymic == other.Patronymic &&
                MobileNumber == other.MobileNumber &&
                BirthdayDate == other.BirthdayDate &&
                Price == other.Price;
        }

        public IProduct Clone()
        {
            return this.MemberwiseClone() as IProduct;
        }
    }
}
