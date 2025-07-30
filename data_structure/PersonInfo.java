import java.util.Scanner;
import java.time.Year;

public class PersonInfo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Reading the data
        System.out.print("Enter your name: ");
        String name = input.nextLine();

        System.out.print("Enter your year of birth: ");
        int yearOfBirth = input.nextInt();

        System.out.print("Enter your gender (M/F): ");
        char gender = input.next().charAt(0);

        System.out.print("Enter grade 1: ");
        int grade1 = input.nextInt();

        System.out.print("Enter grade 2: ");
        int grade2 = input.nextInt();

        // Calculate the current year
        int currentYear = Year.now().getValue();
        int age = currentYear - yearOfBirth;

        // Calculate the average grade
        double average = (grade1 + grade2) / 2.0;

        // Output
        System.out.println("\n--- Person Information ---");
        System.out.println("Name: " + name);
        System.out.println("Gender: " + gender);
        System.out.println("Age: " + age + " years");
        System.out.println("Average grade: " + average);

        if (average > 8) {
            System.out.println("Result: Approved");
        } else {
            System.out.println("Result: Final Exam");
        }

        input.close();
    }
}