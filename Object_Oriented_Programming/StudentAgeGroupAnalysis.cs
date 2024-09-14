using System;

class Program
{
    static void Main()
    {
        int totalStudents = 0;
        int[] ageGroups = new int [5];
        int outOfRangeCount = 0;
        
        Console.WriteLine("Enter the number of students: ");
        totalStudents = Convert.ToInt32(Console.ReadLine());
        
        if (totalStudents <= 0)
        {
            Console.WriteLine("The number of students must be greather than zero.");
            return;
        }
        
        for (int i = 0; i < totalStudents; i++)
        {
            Console.Write($"Enter the age of student {i + 1}: ");
            int age = Convert.ToInt32(Console.ReadLine());
            
            if (age >= 15 && age <= 18)
            {
                ageGroups[0]++;
            }
            else if (age >= 19 && age <= 21)
            {
                ageGroups[1]++;
            }
            else if (age >= 22 && age <= 25)
            {
                ageGroups[2]++;
            }
            else if (age >= 26 && age <= 30)
            {
                ageGroups[3]++;
            }
            else if (age > 30)
            {
                ageGroups[4]++;
            }
            else
            {
                outOfRangeCount++;
            }
        }
        
        double percentageLastGroup = (ageGroups[4] / (double)totalStudents) * 100;
        
        Console.WriteLine("\nResults:");
        Console.WriteLine($"Total number of students: {totalStudents}");
        Console.WriteLine($"Number of students in age range 15-18: {ageGroups[0]}");
        Console.WriteLine($"Number of students in age range 19-21: {ageGroups[1]}");
        Console.WriteLine($"Number of students in age range 22-25: {ageGroups[2]}");
        Console.WriteLine($"Number of students in age range 26-30: {ageGroups[3]}");
        Console.WriteLine($"Number of students in age range over 30: {ageGroups[4]}");
        Console.WriteLine($"Number of students not in any age group: {outOfRangeCount}");
        Console.WriteLine($"Percentage of students in the last age group: {percentageLastGroup:F2}%");
    }
}
