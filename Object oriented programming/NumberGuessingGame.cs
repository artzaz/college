using System;

class Program
{
    static void Main()
    {
        int number = -1;
        
        while (number != 92)
        {
            Console.Write("Enter an integer between 0 and 100: ");
            number = Convert.ToInt32(Console.ReadLine());
            
            if (number < 0 || number > 100)
            {
                Console.WriteLine("The number must be between 0 and 100. Please try again.");
            }
            else if (number != 92)
            {
                Console.WriteLine("Try again.");
            }
        }
        Console.WriteLine("You entered 92. Program exiting.");
    }
}
