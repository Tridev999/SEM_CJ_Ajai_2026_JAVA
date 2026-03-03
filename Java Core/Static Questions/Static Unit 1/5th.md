import java.util.Scanner;

public class Main {
public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

    int monthlyRent = scanner.nextInt();
        int leaseDuration = scanner.nextInt();

    int totalCost = monthlyRent * leaseDuration;

    String paymentMethod = null;

    int totalCostCategory;

    if (totalCost <= 1000) {
            totalCostCategory = 1;
        } else if (totalCost <= 5000 && totalCost>1000) {
            totalCostCategory = 2;
        } else {
            totalCostCategory = 3;
        }

    switch (totalCostCategory) {
            case 1:
                paymentMethod = "Payment by cash or check is recommended.";
                break;
            case 2:
                paymentMethod = "Payment by credit card is recommended.";
                break;
            case 3:
                paymentMethod = "Payment by bank transfer is recommended.";
                break;
        }

    System.out.println("Total Cost: " + totalCost);
        if (paymentMethod != null) {
            System.out.println("Payment Method Suggestion: " + paymentMethod);
        }

    scanner.close();
    }

}
