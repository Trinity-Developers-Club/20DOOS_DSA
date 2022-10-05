public class pow {

        public static int myPow(int x, int n) {
            
            if(n==0){
                return 1;
                
            }
            int halfpow=myPow(x, n/2);
            int halfpowsq= halfpow*halfpow;
             if (n < 0) {
            return (1 / x) * myPow(1 / x, -(n + 1));
            }
            
            if(n%2!=0){
                halfpowsq= x*halfpowsq;
                
            }
            return halfpowsq;
        }
   public static void main(String[] args) {

            System.out.println(myPow(2,5));
            
         }
    }

