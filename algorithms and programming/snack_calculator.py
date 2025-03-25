# Program to calculate the total cost of snacks based on product code and quantity
def calculate_bill():
    # Snack menu with product codes and prices
    print("Snack Menu:")
    print("Code 1 - Coxinha: R$3.50")
    print("Code 2 - Pastel: R$4.00")
    print("Code 3 - Empada: R$3.00")
    print("Code 4 - Kibe: R$3.80")

    # Read the product code and quantity
    product_code = int(input("\nEnter the product code (1-4): "))
    quantity = int(input("Enter the quantity: "))

    # Calculate the total using match-case
    match product_code:
        case 1:
            price = 3.50  # Coxinha
            product_name = "Coxinha"
        case 2:
            price = 4.00  # Pastel
            product_name = "Pastel"
        case 3:
            price = 3.00  # Empada
            product_name = "Empada"
        case 4:
            price = 3.80  # Kibe
            product_name = "Kibe"
        case _:
            print("Invalid product code! Please enter a code between 1 and 4.")
            return  # Exit the function if the code is invalid

    # Calculate and display the total
    total = price * quantity
    print(f"\nProduct: {product_name}")
    print(f"Quantity: {quantity}")
    print(f"Total to pay: R${total:.2f}")

# Run the program
calculate_bill()
