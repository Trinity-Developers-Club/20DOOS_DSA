class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int ans = 0;
        // hashmap approach
        unordered_map<char, int> mpp1;
        for (int i = 0; i < stones.length(); i++)
        {
            mpp1[stones[i]]++;
        }

        for (int i = 0; i < jewels.length(); i++)
        {
            if (mpp1.find(jewels[i]) != mpp1.end())
                ans += mpp1[jewels[i]];
        }
        return ans;
    }
};