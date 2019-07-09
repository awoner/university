using System;

namespace ArchitectureLab1.Interfaces
{
    public interface INotebook : IProduct
    {
        string Name { get; set; }
        string Surname { get; set; }
        string Patronymic { get; set; }
        string MobileNumber { get; set; }
        DateTime BirthdayDate { get; set; }
    }
}