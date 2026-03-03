import java.util.Scanner;
public class Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str=sc.nextLine();
        String rev;
        rev="";
        for(int i=str.length()-1; i>=0; i--){
            rev=rev+str.charAt(i);
        }
        if(str.equals(rev)){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }
        sc.close();
    }
}

