import java.util.*;
public class twoSumarray {
    public static  int[] twoSum(int arr[], int target) {
        int ans[]=new int[arr.length];
        for(int i=0;i<arr.length;i++){
        for(int j=i+1;j<arr.length;j++){
            if(arr[i]+arr[j]==target){
                ans[0]=i;
                ans[1]=j;
                break;
            }
        }
        }
        return ans;
    }
   public static void main(String args[]){
        System.out.println("ENTER SIZE OF  ARRAY : ");

        try (//int arr[]=new int[arr.length];
        Scanner sc = new Scanner(System.in)) {
            int n= sc.nextInt();
            int arr[]=new int[n];
                for(int i=0;i<arr.length;i++){
                    arr[i]=sc.nextInt();
                }
                System.out.println("TARGET VALUE:");
                int target=sc.nextInt();
                System.out.print(twoSum(arr,target));
        }
    }
}

