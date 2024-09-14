using System;

class Program
{
    static void Main()
    {
        Random random = new Random();
        int userNumber = 0;
        int randomNumber;
        int sum = 0;
        
        while (true)
        {
            Console.WriteLine("Enter a number between 1 and 132: ");
            userNumber = Convert.ToInt32(Console.ReadLine());
            
            if (userNumber >= 1 && userNumber <= 132)
                break;
            else
                Console.WriteLine("Invalid number! Please enter a number between 1 and 132.");
        }
        
        do
        {
            randomNumber = random.Next(1, 133);
            sum += randomNumber;
            Console.WriteLine($"Generated number: {randomNumber}");
        } while (randomNumber != userNumber);
        
        Console.WriteLine($"\nThe sum of generated numbers is: {sum}");
    }
}
