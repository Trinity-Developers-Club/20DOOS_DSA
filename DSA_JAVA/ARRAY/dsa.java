public class dsa{
    
    public static int sumsecondrow(int nums[][]) {
        int sum=0;
    //for(int i=0;i<nums.length;i++){
        for(int j=0;j<nums[0].length;j++){
            //if(i==1 && j<=2){
              sum+= nums[1][j];
            }
        
       return sum;      
    }
    public static void main(String args[]) {
        int nums[][] = { {1,4,9},{11,4,3},{2,2,3} };
        System.out.println(sumsecondrow(nums));
        
    }
}
