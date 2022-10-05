public class tower {
    
    public static void towerofhanoi(int n , String src , String help, String dest){
//A-SOURCE , B-HELPER, C-DESTINATION
  if(n==1){
   System.out.println("transfer disk"+ n+  "from" + src+ "to" +dest);
   return;

  }
  //transfer top n-1 from src to helper using dest as 'helper'
  towerofhanoi( n-1, src, dest, help);
  System.out.println("transfer disk"+ n +  "from" + src+ "to" +dest);
  //transfer n-1 from helper to dest using srcas 'helper'
  towerofhanoi( n-1, help, src, dest);

    }
    public static void main(String args[]) 
    {
        int n=3;
        towerofhanoi(n,"A","B","C");
        
    }
}
