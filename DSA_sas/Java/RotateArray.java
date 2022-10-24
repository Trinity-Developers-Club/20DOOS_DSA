//Java Program to Rotate an Array by n Elements.
 
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class RotateArray {
    // Function to rotate the array elements
    static void rotateArray(int[] array, int n){
        int i,j,temp,temp1;
        for(i=1;i<=n;i++){
            temp = array[0];
            for(j=0;j<array.length;j++){
                temp1 = array[(j+1) % array.length];
                array[(j+1) % array.length] = temp;
                temp = temp1;
            }
        }
    }
    // main function to read the array and display the output
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size;
        System.out.println("Enter the size of the array");
        try {
            size = Integer.parseInt(br.readLine());
        } catch (Exception e) {
            System.out.println("Invalid Input");
            return;
        }
        int[] array = new int[size];
        System.out.println("Enter array elements");
        int i;
        for (i = 0; i < array.length; i++) {
            try {
                array[i] = Integer.parseInt(br.readLine());
            } catch (Exception e) {
                System.out.println("An error occurred");
                return;
            }
        }
        System.out.println("The contents of the array before rotation are");
        for(i=0;i<array.length;i++){
            System.out.print(array[i] + " ");
        }
        System.out.println();
        int n;
        System.out.println("Enter the number by which the array elements are to " 
                            + "be rotated");
        try{
            n=Integer.parseInt(br.readLine());
        }catch (Exception e){
            System.out.println("An error occurred");
            return;
        }
        rotateArray(array,n);
        System.out.println("The contents of the array after rotation are");
        for(i=0;i<array.length;i++){
            System.out.print(array[i] + " ");
        }
    }
}