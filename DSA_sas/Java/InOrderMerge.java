// Java Program to Merge Two Arrays in Order.
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
 
public class InOrderMerge {
    // Function to merge the arrays
    static int[] mergeArrays(int[] arrayOne,int[] arrayTwo)
    {
        int totalLength=arrayOne.length +arrayTwo.length;
        int[] c=new int[totalLength];
        int j,k,index=0;
        j=0;
        k=0;
        while((j!=arrayOne.length) && (k!=arrayTwo.length)){
            if(arrayOne[j]<=arrayTwo[k])
            {
                c[index++]=arrayOne[j++];
            }
            else
            {
                c[index++]=arrayTwo[k++];
            }
        }
        while(k!=arrayTwo.length)
        {
            c[index++]=arrayTwo[k++];
        }
        while(j!=arrayOne.length)
        {
            c[index++]=arrayOne[j++];
        }
        return c;
    }
    // Function to read input and display the output
    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m, n;
        System.out.println("Enter the size of the two arrays");
        try {
            n = Integer.parseInt(br.readLine());
            m = Integer.parseInt(br.readLine());
        }
        catch (IOException e)
        {
            System.out.println("Invalid input");
            return;
        }
        int[] arrayOne = new int[n];
        int[] arrayTwo = new int[m];
        System.out.println("Enter the first array elements");
        int i,j;
        for(i=0; i<arrayOne.length; i++){
            try {
                arrayOne[i] = Integer.parseInt(br.readLine());
            }
            catch (IOException e)
            {
                System.out.println("Invalid array element. Enter it again");
                i--;
            }
        }
        System.out.println("Enter the second array elements");
        for(i=0; i<arrayTwo.length; i++){
            try {
                arrayTwo[i] = Integer.parseInt(br.readLine());
            }
            catch (IOException e)
            {
                System.out.println("Invalid array element. Enter it again");
                i--;
            }
        }
        Arrays.sort(arrayOne);
        Arrays.sort(arrayTwo);
        int[] mergedArray=mergeArrays(arrayOne,arrayTwo);
        System.out.println("The merged array is");
        for(i=0;i<mergedArray.length;i++)
        {
            System.out.print(mergedArray[i]+" ");
        }
    }
}