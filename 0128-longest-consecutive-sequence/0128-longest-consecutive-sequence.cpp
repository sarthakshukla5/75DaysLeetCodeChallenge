class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        for(auto it : s) {

            if(s.find(it - 1) == s.end()) {

                int count = 1;
                int x = it;

                while(s.find(x + 1) != s.end()) {
                    x++;
                    count++;
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};