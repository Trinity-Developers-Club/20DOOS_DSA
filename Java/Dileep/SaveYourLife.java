//{ Driver Code Starts
    import java.io.*;
    import java.util.*;
    
    // } Driver Code Ends
    class Solution{
        static String maxSum(String w,char x[],int b[], int n){
            //code here
            HashMap<Character,Integer> hm = new HashMap<>();
            StringBuilder sb = new StringBuilder();
            StringBuilder ans = new StringBuilder();
            for(int i=0;i<n;i++)
            hm.put(x[i],b[i]);
            
            for(int i=0;i<w.length();i++)
            {
                if(!hm.containsKey(w.charAt(i)))
                {
                    hm.put(w.charAt(i),(int)w.charAt(i));
                }
            }
            int sum=0,max_sum=Integer.MIN_VALUE;
            for(int i=0;i<w.length();i++)
            {
                sum+=hm.get(w.charAt(i));
                sb.append(w.charAt(i));
                if(max_sum<sum)
                {
                    max_sum=sum;
                    ans.setLength(0);
                    ans.append(sb);
                }
                if(sum<0)
                {
                    sum=0;
                    sb.setLength(0);
                }
            }
            return ans.toString();
        }
    }
    
    //{ Driver Code Starts.
    class GFG
    {
        public static void main(String args[])throws IOException
        {
            BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(read.readLine());
            while(t-- > 0)
            {
                String w = read.readLine();
                int n = Integer.parseInt(read.readLine());
                String TE[] = read.readLine().trim().split(" ");
                char x[] = new char[n];
                for(int i = 0;i<n;i++)
                {
                    x[i] = TE[i].charAt(0);
                }
                
                String TR[] = read.readLine().trim().split(" ");
                int b[] = new int[n];
                for(int i = 0;i<n;i++)
                {
                    b[i] = Integer.parseInt(TR[i]);
                }
               
                Solution ob = new Solution();
                System.out.println(ob.maxSum(w,x,b,n));
            }
        }
    }