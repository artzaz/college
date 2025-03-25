# Program to sort two dates in ascending order
def sort_dates():
    # Read the first date
    print("Enter the first date:")
    day1 = int(input("Day: "))
    month1 = int(input("Month: "))
    year1 = int(input("Year: "))

    # Read the second date
    print("Enter the second date:")
    day2 = int(input("Day: "))
    month2 = int(input("Month: "))
    year2 = int(input("Year: "))

    # Convert dates to a comparable format (tuple: year, month, day)
    date1 = (year1, month1, day1)
    date2 = (year2, month2, day2)

    # Compare and sort the dates
    if date1 <= date2:
        earlier_date = date1
        later_date = date2
    else:
        earlier_date = date2
        later_date = date1

    # Display the dates in ascending order
    print("\nDates in ascending order:")
    print(f"1st: {earlier_date[2]}/{earlier_date[1]}/{earlier_date[0]}")
    print(f"2nd: {later_date[2]}/{later_date[1]}/{later_date[0]}")

# Run the program
sort_dates()
