import java.util.Scanner;
import java.util.Stack;
 
public class AB_BB {
    public static void main(String[] args) {
        int numOfTestcases,final_size;
        String str;
 
        Scanner scan = new Scanner(System.in);
        numOfTestcases = scan.nextInt();
        scan.nextLine();
        for(int i=0;i<numOfTestcases;i++){
            str = scan.nextLine();
            final_size = remove_AB_BB(str);
            System.out.println(final_size);
        }
 
        scan.close();
    }
 
    static int remove_AB_BB(String str){
        Stack<Character> str_Stack = new Stack<Character>();
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='B' && str_Stack.size()>0){
                str_Stack.pop();
            }else{
                str_Stack.push(str.charAt(i));
            }
        }
 
        return str_Stack.size();
    }
}