class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int left=0,right=1;
        if(colors.length()==0 || colors.length()==1){
            return 0;
        }
        int result=0;
        int min1=0;
        int time=neededTime[left];
        for( right=1;right<colors.size();right++){
            if(colors[left]==colors[right]){
                min1=max(time,neededTime[right]); 
                time=min(time,neededTime[right]);
                cout<<time<<" ";
                result+=time;
                time=min1;  
            }
            else{ 
                left=right;
                time=neededTime[left];
            }
        }
        
        return result;
    }
};
