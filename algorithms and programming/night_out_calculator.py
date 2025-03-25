# Program to estimate the cost of a night out with friends
def estimate_night_out():
    # Dictionary with expense categories and their estimated costs
    expenses = {
        "Dinner": 50.00,
        "Drinks": 30.00,
        "Transportation (e.g., taxi/ride-share)": 20.00,
        "Club entry fee": 15.00,
        "Snacks": 10.00,
        "Other (e.g., games, tips)": 15.00
    }

    total_cost = 0.0

    # Ask about each expense
    print("Let's estimate your night out expenses!")
    for expense, cost in expenses.items():
        answer = input(f"Do you plan to spend on {expense} (estimated R${cost:.2f})? (yes/no): ").lower()
        if answer == "yes":
            total_cost += cost

    # Ask how many people are going out
    num_people = int(input("\nHow many people (including you) are going out? "))

    # Calculate the total cost for everyone
    total_cost_all = total_cost * num_people

    # Display the result
    print(f"\nEstimated cost per person: R${total_cost:.2f}")
    print(f"Total cost for {num_people} people: R${total_cost_all:.2f}")
    print("Have fun, but don’t blame me if your wallet cries tomorrow!")

# Run the program
estimate_night_out()
