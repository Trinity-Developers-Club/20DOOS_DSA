QUESTION: https://leetcode.com/problems/longest-common-prefix/
Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.



  
  
CODE:
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0)
            return "";
        String prefix = strs[0];
        for(int i=0;i<strs.length;i++){
            while(strs[i].indexOf(prefix)!=0){
                prefix = prefix.substring(0,prefix.length()-1);
                if(prefix.isEmpty()){
                    return "";
                    
                }
            }
        }
        return prefix;
        
    }
}
