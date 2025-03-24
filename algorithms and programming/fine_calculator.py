# Program to calculate speeding fines
def calculate_fine():
    # Request user input
    speed_limit = float(input("Enter the speed limit of the road (in km/h): "))
    driver_speed = float(input("Enter the driver's speed (in km/h): "))

    # Calculate the percentage of excess speed
    if driver_speed > speed_limit:
        excess = ((driver_speed - speed_limit) / speed_limit) * 100

        # Determine the type of violation and fine
        if excess <= 20:
            print("\nMedium Violation")
            print("Exceeded speed by up to 20%")
            print("Fine amount: R$85.00")
            print("Points on license: 4 points")

        elif excess <= 50:
            print("\nSerious Violation")
            print(f"Exceeded speed by {excess:.1f}%")
            print("Fine amount: R$127.00")
            print("Points on license: 5 points")

        else:
            print("\nVery Serious Violation")
            print(f"Exceeded speed by {excess:.1f}%")
            print("Fine amount: R$574.00")
            print("Points on license: 7 points")
            print("Additional consequences: License seizure and suspension of driving rights")

    else:
        print("\nThe driver was within the allowed speed limit.")
        print("No fine will be issued.")

# Run the program
print("=== Fine Calculator - Federal Highway Police ===")
calculate_fine()
