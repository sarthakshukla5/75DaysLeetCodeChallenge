class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // We don't need to jump from the last index, so i < n - 1
        for (int i = 0; i < n - 1; ++i) {
            // Keep track of the farthest point reachable
            farthest = max(farthest, i + nums[i]);
            
            // If we reached the end of the current jump range
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                // If we can already reach the end, break early
                if (current_end >= n - 1) break;
            }
        }
        
        return jumps;
    }
};