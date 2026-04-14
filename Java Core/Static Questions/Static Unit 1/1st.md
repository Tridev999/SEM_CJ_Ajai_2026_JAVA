import java.util.Scanner;
public class Main {
public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

    String deviceName = scanner.nextLine();
        String status = scanner.nextLine();
        int modelNumber = scanner.nextInt();

    System.out.println("Device Name: " + deviceName);
        System.out.println("Status: " + status);
        System.out.println("Model Number: " + modelNumber);
    }

}
