public class numbertostring {
     static String digit[]={"zero","one", "two", "three", "four", "five", "six",
      "seven", "eight", "nine", "ten"};
    public static void printdigits(int n){
        if(n==0){
            return;
        }
        int lastdigit=n%10;
        printdigits(n/10);
        System.out.print(digit[lastdigit]+ " ");
    }
    public static void main(String args[]){
    printdigits(4353);
    System.out.println();
    }
}
