// Ques:https://leetcode.com/problems/combination-sum-ii/

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
         List<List<Integer>> ans=new ArrayList<>();
        List<Integer>li=new ArrayList<>();
        Arrays.sort(candidates);
        func(candidates,target,0,li,ans,0);
        return ans;
    }
    public static void func(int[]candidates,int target,int sum,List<Integer>li,List<List<Integer>>ans,int index){
        if(sum==target){
            ans.add(new ArrayList<>(li));
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=index;i<candidates.length;++i){
         if(i>index&&(candidates[i]==candidates[i-1]))
             continue;
            if(target<sum)
                break;
             
                  li.add(candidates[i]);
                func(candidates,target,sum+candidates[i],li,ans,i+1);
                    li.remove(li.size()-1); 
            }
            
             
}        }
    
