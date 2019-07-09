using System;

namespace ArchitectureLab1.Entities
{
    public class Date
    {
        public DateTime BirthdayDate { get; set; }

        public override string ToString()
        {
            return $"{BirthdayDate.Day}-{BirthdayDate.Month}-{BirthdayDate.Year}";
        }
    }
}
