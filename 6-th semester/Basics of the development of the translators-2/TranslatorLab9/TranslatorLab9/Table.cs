using System;
using System.Collections.Generic;

namespace TranslatorLab9
{
    public class Table
    {
        public int Size { get; private set; }
        public (string Name, int Value)[] Records { get; private set; }

        public Table(int size, int fillingPercentage)
        {
            Size = size;
            Records = new (string, int)[Size];

            FillTable(size, fillingPercentage);
        }

        private void FillTable(int size, int fillingPercentage)
        {
            int index;
            Random random = new Random();
            size = fillingPercentage * size / 100;
            (string Name, int Value) record;

            for (int i = 0; i < size; i++)
            {
                record = (GetRandomName(), random.Next());

                do
                {
                    index = random.Next(size);
                    if (string.IsNullOrEmpty(Records[index].Name))
                    {
                        Records[index] = record;
                        break;
                    }
                }
                while (!string.IsNullOrEmpty(Records[index].Name));
            }
        }

        private string GetRandomName()
        {
            Random random = new Random();
            string newName = string.Empty;
            int nameLength = random.Next(2, 6);

            newName += (char)random.Next(65, 90);   //65-90 [A-Z]

            for (int i = 0; i < nameLength; i++)
            {
                newName += (char)random.Next(97, 122);  //97-122 [a-z]
            }

            return newName;
        }

        private int GetAttemptsCount((string Name, int Value) record, RehashMethod rehashMethod)
        {
            int a = 46, b = 76, c = 45, i;
            long h1;
            uint h0 =(uint) record.GetHashCode();

            if (string.IsNullOrEmpty(Records[h0 % Size].Name) || Records[h0 % Size].Name == record.Name)
            {
                return 1;
            }

            for (i = 1; i < Size; i++)
            {
                switch (rehashMethod)
                {
                    case RehashMethod.Linear:
                        h1 = (h0 + i) % Size;
                        break;
                    case RehashMethod.Quadratic:
                        h1 = (h0 + a * (int)Math.Pow(i, 2) + b * i + c) % Size;
                        break;
                    default:
                        throw new Exception("Undefined rehashing method!");
                }

                if (string.IsNullOrEmpty(Records[h1].Name) || Records[h1].Name == record.Name)
                {
                    return ++i;
                }
            }

            return i;
        }

        public float GetAverageAddsCount(int addsCount, RehashMethod rehashMethod)
        {
            (string, int) record = (GetRandomName(), new Random().Next());

            float avgAddsCount = 0;
            for (int i = 0; i < addsCount; i++)
            {
                avgAddsCount += GetAttemptsCount(record, rehashMethod);
            }

            avgAddsCount /= 100.0f;

            return avgAddsCount;
        }

        public override string ToString()
        {
            string table = string.Empty;
            foreach (var record in Records)
            {
                table += $"{record.Name}\t{record.Value}\n";
            }
            return base.ToString();
        }
    }
}
