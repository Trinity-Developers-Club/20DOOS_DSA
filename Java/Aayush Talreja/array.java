import java.util.Arrays;

public class array {
    public static void main(String[] args) {
    // 1D ARRAY
    //     int[] arr = new int[5]; // Initialize the array
    //     int count = 0; //result

    //     //loop to include values in array
    //     for(int i=0; i<arr.length; i++){
    //         arr[i] = count;
    //         count++;
    //     }
        
    //     // loop to print the array elements
    //     for(int j=0; j<arr.length; j++){
    //         System.out.println(arr[j]);
    //     }
    // }

    // 2D ARRAY
    // int[][] arr = new int [3][4];
    // int count = 1;

    // for(int i=0; i<arr.length; i++){
    //     for(int j=0; j<arr[i].length; j++){
    //         arr[i][j] = count;
    //         count++;
    //     }
    // }

    // for(int i=0; i<arr.length; i++){
    //     for(int j=0; j<arr[i].length; j++){
    //         System.out.print(arr[i][j] + " ");
    //     }
    //     System.out.println();
    // }    

    // SORTING IN ARRAY
    int[] arr = new int[] {2, 6, 8, 3, 1};
    
    for(int i=0; i<arr.length; i++){
        System.out.print(arr[i]);
    }

    System.out.println();

    Arrays.sort(arr);
    for(int i=0; i<arr.length; i++){
        System.out.print(arr[i]);
    }
}
}