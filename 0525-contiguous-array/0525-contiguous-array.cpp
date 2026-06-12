class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int inc = 0, n = nums.size(), ans = 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                inc++;
            else
                inc--;

            if (mp.count(inc)) {
                ans = max(ans, i - mp[inc]);
            } else {
                mp[inc] = i;
            }
        }

        return ans;
    }
};