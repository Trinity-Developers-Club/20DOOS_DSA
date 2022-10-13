class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int t=nums.size()-1;
        while(t>=2){
        if(nums[t]+nums[t-1]>nums[t-2] && nums[t-2]+nums[t-1]>nums[t] && nums[t]+nums[t-2]>nums[t-1]){
            return nums[t]+nums[t-1]+nums[t-2];
        }
        t--;
        }
        return 0;
    }
};
