public class profit{
    public static int buyandsell(int prices[]){
        int maxprofit=0;
        int buyprice=Integer.MAX_VALUE;
        //CALCULATE MAXIMUM PROFIT
        for(int i=0;i<prices.length;i++){
            if(buyprice<prices[i]){
              int profit=prices[i]- buyprice;
              maxprofit=Integer.max(maxprofit, profit);
            }
            else{
                buyprice=prices[i];
            }
        }
    return maxprofit;

    }
    public static void main(String args[]) {
     int prices[]={7,1,5,3,6,4};
     System.out.println("MAXIMUM PROFIT: ");
        System.out.println(buyandsell(prices));
        
    }
}