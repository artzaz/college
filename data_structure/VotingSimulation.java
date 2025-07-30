import java.util.Scanner;

public class VotingSimulation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int votesAlice = 0;
        int votesBruno = 0;

        System.out.println("Voting for Class Representative:");
        System.out.println("Type 1 to vote for Alice");
        System.out.println("Type 2 to vote for Bruno");

        for (int i = 1; i <= 5; i++) {
            System.out.print("Vote #" + i + ": ");
            int vote = input.nextInt();
            if (vote == 1) {
                votesAlice++;
            } else if (vote == 2) {
                votesBruno++;
            } else {
                System.out.println("Invalid vote, try again.");
                i--; // repeat this vote
            }
        }

        System.out.println("\n--- Voting Results ---");
        System.out.println("Alice received: " + votesAlice + " votes");
        System.out.println("Bruno received: " + votesBruno + " votes");

        if (votesAlice > votesBruno) {
            System.out.println("Winner: Alice");
        } else if (votesBruno > votesAlice) {
            System.out.println("Winner: Bruno");
        } else {
            System.out.println("Result: It's a tie!");
        }

        input.close();
    }
}