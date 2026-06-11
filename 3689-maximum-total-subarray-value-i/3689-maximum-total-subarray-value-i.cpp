class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
     int min_val = nums[0];
        int max_val = nums[0];
           for (int x : nums) {
            if (x < min_val) min_val = x;
            if (x > max_val) max_val = x;
        }   
long long diff = (long long)max_val - min_val;
        return diff * k; 
    }
};