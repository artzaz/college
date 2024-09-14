using System;

class Program
{
    static void Main()
    {
        Random random = new Random();
        int number = -1;
        int iterations = 0;
        
        while (number != 48)
        {
            number = random.Next(0, 101);
            iterations++;
            Console.WriteLine($"Iteration {iterations}: Generated number = {number}");
        }
        
        Console.WriteLine($"It took {iterations} iterations to generate the number 48.");
    }
}    
        
        
   
