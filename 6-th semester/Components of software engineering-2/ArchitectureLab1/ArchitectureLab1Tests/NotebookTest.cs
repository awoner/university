using ArchitectureLab1.Entities;
using NUnit.Framework;
using System;

namespace ArchitectureLab1Tests
{
    [TestFixture]
    public class NotebookTest
    {
        [Test]
        public void GetNameTest()
        {
            //arrange
            var notebook = new Notebook();
            string expected = "Oleksiy";
            notebook.Name = "Oleksiy";

            //assert
            Assert.AreEqual(expected, notebook.Name);
        }

        [Test]
        public void GetSurnameTest()
        {
            //arrange
            var notebook = new Notebook();
            string expected = "Artamonov";
            notebook.Surname = "Artamonov";

            //assert
            Assert.AreEqual(expected, notebook.Surname);
        }

        [Test]
        public void GetPatronymicTest()
        {
            //arrange
            var notebook = new Notebook();
            string expected = "Yuriyovich";
            notebook.Patronymic = "Yuriyovich";

            //assert
            Assert.AreEqual(expected, notebook.Patronymic);
        }

        [Test]
        public void GetMobileNumberTest()
        {
            //arrange
            var notebook = new Notebook();
            string expected = "+380988423041";
            notebook.MobileNumber = "+380988423041";

            //assert
            Assert.AreEqual(expected, notebook.MobileNumber);
        }

        [Test]
        public void GetBirthdayDateTest()
        {
            var notebook = new Notebook();
            var expected = new DateTime(1999, 6, 7);
            notebook.BirthdayDate = new DateTime(1999, 6, 7);

            //assert
            Assert.AreEqual(expected, notebook.BirthdayDate);
        }

        [Test]
        public void SetNameTest()
        {
            //arrange
            var notebook = new Notebook();
            string expected = "Oleksiy";
            notebook.Name = "Oleksiy";

            //assert
            Assert.AreEqual(expected, notebook.Name);
        }

        [Test]
        public void SetSurnameTest()
        {
            //arrange
            var notebook = new Notebook();
            string expected = "Artamonov";
            notebook.Surname = "Artamonov";

            //assert
            Assert.AreEqual(expected, notebook.Surname);
        }

        [Test]
        public void SetPatronymicTest()
        {
            //arrange
            var notebook = new Notebook();
            string expected = "Yuriyovich";
            notebook.Patronymic = "Yuriyovich";

            //assert
            Assert.AreEqual(expected, notebook.Patronymic);
        }

        [Test]
        public void SetMobileNumberTest()
        {
            //arrange
            var notebook = new Notebook();
            string expected = "+380988423041";
            notebook.MobileNumber = "+380988423041";

            //assert
            Assert.AreEqual(expected, notebook.MobileNumber);
        }

        [Test]
        public void SetBirthdayDateTest()
        {
            var notebook = new Notebook();
            var expected = new DateTime(1999, 6, 7);
            notebook.BirthdayDate = new DateTime(1999, 6, 7);

            //assert
            Assert.AreEqual(expected, notebook.BirthdayDate);
        }

        [Test]
        public void ToStringTest()
        {
            //arrange
            var notebook = new Notebook()
            {
                Name = "Alex",
                Surname = "Artamonov",
                Patronymic = "Yuriyovich",
                MobileNumber = "+380988423041",
                BirthdayDate = new DateTime(1999, 6, 7)
            };

            string expected = "Name: Alex\n" +
                    "Surname: Artamonov\n" +
                    "Patronymic: Yuriyovich\n" +
                    "Mobile number: +380988423041\n" +
                    "Birthday date: 7-6-1999\n" + 
                    "Price: 0\n";

            //act
            string actual = notebook.ToString();

            //assert
            Assert.AreEqual(expected, actual);
        }

        [Test]
        public void GetDaysBeforeBirthdayTest()
        {
            //arrange
            var notebook = new Notebook()
            {
                Name = "Alex",
                Surname = "Artamonov",
                Patronymic = "Yuriyovich",
                MobileNumber = "+380988423041",
                BirthdayDate = DateTime.Now
            };

            uint expected = 1;

            //act
            uint actual = notebook.GetDaysBeforeBirthday();

            //assert
            Assert.AreEqual(expected, actual);
        }
    }
}
