using System;

class Program
{
    static void Main(string[] args)
    {
        
        string city;
        double temperatureCelsius, temperatureFahrenheit, temperatureKelvin;

        
        Console.WriteLine("Enter the name of your city:");
        city = Console.ReadLine();

        
        Console.WriteLine("Enter the current temperature in degrees Celsius:");
        temperatureCelsius = double.Parse(Console.ReadLine());

        
        temperatureFahrenheit = temperatureCelsius * 1.8 + 32;

        
        temperatureKelvin = temperatureCelsius + 273;

        
        Console.WriteLine($"In the city of {city}, the current temperature is:");
        Console.WriteLine($"{temperatureCelsius}°C in Celsius");
        Console.WriteLine($"{temperatureFahrenheit}°F in Fahrenheit");
        Console.WriteLine($"{temperatureKelvin}K in Kelvin");
    }
}
