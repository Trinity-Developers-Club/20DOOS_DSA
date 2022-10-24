//Java Program to Remove Duplicates in a Sorted Array
 
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class RemoveDuplicates {
    // Function to remove the duplicates
    static int removeDuplicates(int[] array){
        int replaceIndex = 0;
        int i,j;
        for(i=0; i<array.length; i++){
            for(j=i+1; j<array.length; j++){
                if(array[j]!=array[i]){
                    break;
                }
            }
            array[replaceIndex++] = array[i];
            i = j-1;
        }
        return replaceIndex;
    }
    // Function to read user input
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
        System.out.println("Enter array elements in sorted order");
        int i;
        for (i = 0; i < array.length; i++) {
            try {
                array[i] = Integer.parseInt(br.readLine());
            } catch (Exception e) {
                System.out.println("An error occurred");
                return;
            }
        }
        int index = removeDuplicates(array);
        System.out.println("Array after removing duplicates is");
        for(i=0; i<index; i++){
            System.out.print(array[i] + " ");
        }
    }
}