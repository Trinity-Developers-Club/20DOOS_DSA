public class binarystring {

    ///print all binary strings of Size N without consecutive one's(1's)
    public static void printbinstring(int n , int lastplce, String str){
        if(n==0){
            System.out.println(str);
            return ;
        }
         printbinstring(n-1, 0, str+"0");
             if(lastplce==0){
                printbinstring(n-1, 1,str+"1");
             }
             
    }
    public static void main(String args[]) {
  printbinstring(3,0," ");
    }
}
