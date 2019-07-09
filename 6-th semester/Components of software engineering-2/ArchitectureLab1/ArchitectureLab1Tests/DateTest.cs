using ArchitectureLab1.Entities;
using NUnit.Framework;
using System;

namespace ArchitectureLab1Tests
{
    [TestFixture]
    public class DateTest
    {
        [Test]
        public void GetBirthdayDateTest()
        {
            //arrange
            var date = new Date();
            var expected = new DateTime(1999, 6, 7);
            date.BirthdayDate = new DateTime(1999, 6, 7);

            //assert
            Assert.AreEqual(expected, date.BirthdayDate);
        }

        [Test]
        public void SetBirthdayDateTest()
        {
            //arrange
            var date = new Date();
            var expected = new DateTime(1999, 6, 7);
            date.BirthdayDate = new DateTime(1999, 6, 7);

            //assert
            Assert.AreEqual(expected, date.BirthdayDate);
        }

        [Test]
        public void ToStringTest()
        {
            //arrange
            var date = new Date { BirthdayDate = new DateTime(1999, 6, 7) };
            string expected = "7-6-1999";

            //act
            string actual = date.ToString();

            //assert
            Assert.AreEqual(expected, actual);
        }
    }
}
