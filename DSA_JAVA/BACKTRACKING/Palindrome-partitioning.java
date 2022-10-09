// Ques:  https://leetcode.com/problems/palindrome-partitioning/

class Solution {
    public List<List<String>> partition(String s) {
        List<String>li=new ArrayList<>();
List<List<String>>ans=new ArrayList<>();
solution(s,li,ans);
// System.out.println(ans);
        return ans;
	}
public static void solution(String str,List<String>li,List<List<String>>ans) {
	if(str.length()==0) {
		ans.add(new ArrayList<>(li));
		return ;

	}
	for(int i=1;i<=str.length();++i) {
		if(isPlaindrome(str.substring(0,i))) {
			li.add(str.substring(0,i));
			
			solution(str.substring(i),li,ans);
			li.remove(li.size()-1);
		}
		
	}
	
}
public static boolean isPlaindrome(String str) {
	int start=0;
	int end=str.length()-1;
	while(start<end) {
	if(str.charAt(start)!=str.charAt(end))
		return false;
	--end;
	++start;
	}
	return true;
    }
}
