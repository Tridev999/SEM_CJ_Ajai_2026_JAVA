import java.util.*;

class Main {
public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();
        int d = input.nextInt();

    int result = (a + b - c * d / a) % b;

    System.out.println("(a + b - c * d / a) % b = " + result);
}
}
