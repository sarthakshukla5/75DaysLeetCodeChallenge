class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxi = INT_MIN;
    int n = nums.size();
    int curr = 0;
    for(int i =0;i<n;i++) {
        curr=max(curr + nums[i],nums[i]);
        maxi = max(maxi, curr);
    }  
    return maxi;  
    }
};