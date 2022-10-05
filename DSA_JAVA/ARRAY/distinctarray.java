import java.util.*;

public class distinctarray {
     public static boolean distinctelements(int a[]) {
        
         for(int i=0;i<a.length-1;i++){
            for(int j=i+1;j<a.length;j++){
               if(a[i]==a[j]){
                return true;
               }
            }
        }
             
       return false;
     }

     public static void main(String args[]) {
        //int a[]={1,3,4,5,1,3};
        System.out.println("ENTER TOTAL NUMBER OF ARRAY ELEMENTS ");
      try (Scanner sc = new Scanner(System.in)) {
        int size = sc.nextInt();
        int a[]= new int[size];
        System.out.println("ENTER ARRAY ELEMENTS ");  
      for(int k=0;k<size;k++){
        a[k]=sc.nextInt();
         }
   
   System.out.println(distinctelements(a));
    }
    
     
        } 
}
