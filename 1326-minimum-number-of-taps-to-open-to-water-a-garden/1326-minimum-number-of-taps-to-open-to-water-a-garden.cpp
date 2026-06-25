class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // max_reach[i] will store the furthest point reachable from index i
        vector<int> max_reach(n + 1, 0);
        
        for (int i = 0; i <= n; ++i) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            max_reach[left] = max(max_reach[left], right);
        }
        
        int taps = 0;
        int current_end = 0;
        int farthest_reach = 0;
        
        for (int i = 0; i < n; ++i) {
            farthest_reach = max(farthest_reach, max_reach[i]);
            
            // If we have reached the end of the current covered area
            if (i == current_end) {
                // If we can't extend further, it's impossible
                if (farthest_reach <= i) return -1;
                
                taps++;
                current_end = farthest_reach;
            }
        }
        
        return (current_end >= n) ? taps : -1;
    }
};