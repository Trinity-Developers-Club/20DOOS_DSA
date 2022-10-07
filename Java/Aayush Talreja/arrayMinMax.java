// Find out Minimum and Maximum element using array
public class arrayMinMax {
    static int getMin(int arr[], int n){
        int res = arr[0];
        for(int i=1; i<n; i++){
            res = Math.min(res, arr[i]);
        }
    return res;
    }

    static int getMax(int arr[], int n){
        int res = arr[0];

        for(int i=0; i<n; i++){
            res = Math.max(res, arr[i]);
        }
    return res;
    }

    public static void main(String[] args) {
        int arr[] = {12, 56, 72, 24, 5};
        int n = arr.length;
        System.out.println("Minimum Value: " + getMin(arr, n));
        System.out.println("Maximum Value: " + getMax(arr, n));

    }
}
