using System;

namespace TranslatorLab9
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("\tIterations\tTable size\tFilling percentage\tAverage adds count\tRehashing method");
            Console.WriteLine(GetResults(100, 10, 10, RehashMethod.Linear));
            Console.WriteLine(GetResults(100, 100, 10, RehashMethod.Linear));
            Console.WriteLine(GetResults(100, 1000, 10, RehashMethod.Linear));

            Console.WriteLine(GetResults(100, 10, 50, RehashMethod.Linear));

            Console.WriteLine(GetResults(100, 10, 90, RehashMethod.Linear));

            Console.WriteLine();

            Console.WriteLine(GetResults(100, 10, 10, RehashMethod.Quadratic));
            Console.WriteLine(GetResults(100, 100, 10, RehashMethod.Quadratic));
            Console.WriteLine(GetResults(100, 1000, 10, RehashMethod.Quadratic));

            Console.WriteLine(GetResults(100, 10, 50, RehashMethod.Quadratic));

            Console.WriteLine(GetResults(100, 10, 90, RehashMethod.Quadratic));
        }

        static string GetResults(int iterations, int tableSize, double fillingPercentage, RehashMethod rehashMethod)
        {
            float avgAddsCount = 0;
            for (int i = 0; i < iterations; i++)
            {
                Table table = new Table(tableSize, (int)fillingPercentage);
                avgAddsCount += table.GetAverageAddsCount(addsCount: 100, rehashMethod);
            }

            avgAddsCount /= 100.0f;

            return $"\t{iterations}\t\t{tableSize}\t\t{fillingPercentage}%\t\t\t{avgAddsCount}\t\t\t{rehashMethod}";
        }
    }
}
