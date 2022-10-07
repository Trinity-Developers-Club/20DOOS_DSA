// Given two sorted arrays, the task is to merge them in a sorted manner.
public class arrayMerge {
    
    public static void mergeArrays(int[] arr1, int[] arr2, int len1, int len2, int[] result) {
        int i=0, j=0, k=0;
        
        while(i<len1 && j<len2){
            if(arr1[i] < arr2[j]){
                result[k++] = arr1[i++];
            } else{
                result[k++] = arr2[j++];
            }
        }

        while(i < len1){
            result[k++] = arr1[i++];
        }

        while(j < len2){
            result[k++] = arr2[j++];
        }
    }   
    public static void main(String[] args) {
    
    int[] arr1 = {1, 3, 5, 7};
    int len1 = arr1.length;

    int[] arr2 = {2, 4, 6, 8};
    int len2 = arr2.length;

    int[] result = new int[len1 + len2];

    mergeArrays(arr1, arr2, len1, len2, result);

    System.out.println("Merged Array: ");

    for(int i=0; i<len1+len2; i++){
        System.out.print(result[i] + " ");
    }
    }
}
