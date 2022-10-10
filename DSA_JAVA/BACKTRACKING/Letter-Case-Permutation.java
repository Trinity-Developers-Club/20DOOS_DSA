Ques:https://leetcode.com/problems/letter-case-permutation/description/

class Solution {
    public List<String> letterCasePermutation(String s) {
      ArrayList<String>ans=new ArrayList<>();
      func(ans,"",s);
      return ans;  
    }
    public void func(ArrayList<String>ans,String temp,String s){

          if(s.length()==0){
            ans.add(temp);
            return ;
        }
        if(s.charAt(0)>=48&&s.charAt(0)<=57){
            temp+=s.charAt(0);
            s=s.substring(1);
                      if(s.length()==0){
            ans.add(temp);
            return ;
        }
        }
      
        
        char ch=s.charAt(0);
        func(ans,temp+ch,s.substring(1));
        if(ch>='a'&&ch<='z')
        func(ans,temp+(char)(ch-32),s.substring(1));
        else if(ch>='A'&&ch<='Z')
func(ans,temp+(char)(ch+32),s.substring(1));
    }
}
