import java.util.Scanner;

public class LCM {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String lcmString;

        System.out.println("Enter number of test cases you want to run: ");
        int numberOfTestcases = scan.nextInt();
        scan.nextLine();

        for(int i=0;i<numberOfTestcases;i++){
            System.out.println("Enter Frist String: ");
            String str1 = scan.nextLine();
            System.out.println("Enter Second String: ");
            String str2 = scan.nextLine();
            lcmString = stringLcm(str1,str2);
            System.out.println(lcmString);
        }

        scan.close();
        
    }

    static int lcm(int num1, int num2){
        return (num1*num2)/(HCF(num1, num2));       
    }

    static int HCF(int num1,int num2){
        if( num2==0 )
            return num1;
        else
            return HCF(num2, num1%num2);
    }

    static String stringLcm(String str1, String str2){
        int str1_length = str1.length();
        int str2_length = str2.length();
        int lengthOfLcmString = lcm(str1_length,str2_length);
        String lcmString = "";


        for(int i=0;i<lengthOfLcmString;i++){
            if(str1.charAt(i%str1_length) != str2.charAt(i%str2_length)){
                return "-1";
            }
        }

        for(int i=0 ; i< lengthOfLcmString/str1_length; i++){
            lcmString += str1;
        }

        return lcmString;
    }
}