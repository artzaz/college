using System;

class Program
{
    static void Main()
    {
        int number;
        int totalNumbers = 0;
        int evenCount = 0;
        int oddCount = 0;
        int evenSum = 0;
        int oddSum = 0;
        double sumOffAllNumbers = 0;
        
        while (true)
        {
            Console.Write("Enter an integer greater than zero (or 0 to stop):");
            number = Convert.ToInt32(Console.ReadLine());
            
            if (number == 0)
                break;
                
            if (number < 0)
            {
                Console.WriteLine("Please enter a number greater than zero.");
                continue;
            }
            
            totalNumbers++;
            sumOffAllNumbers += number;
            
            if (number %2 == 0)
            {
                evenCount++;
                evenSum += number;
            }
        }
        
        double average = totalNumbers > 0 ? sumOffAllNumbers / totalNumbers : 0;
        
        Console.WriteLine("\nResults:");
        Console.WriteLine($"a. Total numbers entered: {totalNumbers}");
        Console.WriteLine($"b. Even numbers: {evenCount}, Odd numbers: {oddCount}");
        Console.WriteLine($"c. Sum of even numbers: {evenSum}");
        Console.WriteLine($"d. Sum of odd numbers: {oddSum}");
        Console.WriteLine($"e. Average of numbers entered: {average }");
    }
}
