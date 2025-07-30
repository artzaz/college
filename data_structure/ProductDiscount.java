import java.util.Scanner;

public class ProductDiscount {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the product name: ");
        String productName = input.nextLine();

        System.out.print("Enter the product price: ");
        double price = input.nextDouble();

        double discountPercent;
        if (price < 100) {
            discountPercent = 5;
        } else if (price <= 500) {
            discountPercent = 10;
        } else {
            discountPercent = 15;
        }

        double finalPrice = price - (price * discountPercent / 100);

        System.out.println("\n--- Product Information ---");
        System.out.println("Product name: " + productName);
        System.out.println("Original price: R$" + price);
        System.out.println("Discount: " + discountPercent + "%");
        System.out.println("Final price with discount: R$" + finalPrice);

        input.close();
    }
}