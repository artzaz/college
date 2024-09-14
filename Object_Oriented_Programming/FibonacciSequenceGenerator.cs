using System;

class Program
{
    static void Main()
    {
        int n;
        
        while(true)
        {
            Console.Write("Enter the number of terms for the Fibonacci sequence (between 2 and 35):");
            n = Convert.ToInt32(Console.ReadLine());
            
            if (n >= 2 && n <= 35)
                break;
            else
                Console.WriteLine("Invalid number! Please enter a number between 2 and 35.");
        }
        
        long first = 0;
        long second = 1;
        
        Console.WriteLine("Fibonacci sequence:");
        Console.WriteLine(first);
        
        if (n > 1)
        {
            Console.WriteLine(second);
            
            for (int i = 2; i < n; i++)
            {
                long next = first + second;
                Console.WriteLine(next);
                first = second;
                second = next;
            }
        }
    }
}
