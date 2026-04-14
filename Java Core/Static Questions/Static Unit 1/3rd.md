import java.util.Scanner;

class DeadpoolMarathon {
public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

    int totalMovies = scanner.nextInt();

    int moviesBeforeBreak = scanner.nextInt();

    int movieDuration = 45;
        int breakDuration = 15;

    int fullBreaks = (totalMovies - 1) / moviesBeforeBreak;

    int remainingMovies = totalMovies - (fullBreaks * moviesBeforeBreak);

    int totalDuration = (fullBreaks > 0) ?
            (fullBreaks * (moviesBeforeBreak * movieDuration + breakDuration)) + (remainingMovies * movieDuration) :
            (totalMovies * movieDuration);

    System.out.print(totalDuration + " minutes");

    scanner.close();
    }
}
