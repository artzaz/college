# Program to convert month number to full month name
def get_month_name():
    # Read the month number from user input
    month = int(input("Enter the month number (1-12): "))

    # Use match-case to determine the month name
    match month:
        case 1:
            print("January")
        case 2:
            print("February")
        case 3:
            print("March")
        case 4:
            print("April")
        case 5:
            print("May")
        case 6:
            print("June")
        case 7:
            print("July")
        case 8:
            print("August")
        case 9:
            print("September")
        case 10:
            print("October")
        case 11:
            print("November")
        case 12:
            print("December")
        case _:
            print("Invalid month number! Please enter a number between 1 and 12.")

# Run the program
get_month_name()
