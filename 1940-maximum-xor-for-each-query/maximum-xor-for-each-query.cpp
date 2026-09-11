class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int xr = 0;
        for(int i = 0; i < nums.size(); i++) {
            xr ^= nums[i];
        }
        int mask = (1 << maximumBit) - 1;
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; i--) {            
            ans.push_back(xr ^ mask);
            xr ^= nums[i];
        }

        return ans;
    }
};