using System;

class Program
{
    static void Main()
    {
        int number;
        int sumOfDivisors = 0;
        
        Console.Write("Enter a positive integer");
        number = Convert.ToInt32(Console.ReadLine());
        
        if (number <= 0)
        {
            Console.WriteLine("The number must be a positive integer.");
            return;    
        }
        
        for (int i = 1; i < number; i++)
        {
            if (number % i == 0)
            {
                sumOfDivisors += i;
            }
        }
        if (sumOfDivisors == number)
        {
            Console.WriteLine($"{number} is a perfect number.");
        }
        else
        {
            Console.WriteLine($"{number} is not a perfect number.");
        }
    }
}
