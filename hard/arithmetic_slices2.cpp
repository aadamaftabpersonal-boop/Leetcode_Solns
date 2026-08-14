class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<long long, int> mp[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                
                auto it = mp[j].find(diff);
                int count_at_j = (it == mp[j].end()) ? 0 : it->second;
                
                // Add valid length >= 3 subsequences to result
                result += count_at_j;
                
                // Update count at current index (count_at_j extended + new pair)
                mp[i][diff] += count_at_j + 1;
            }
        }
        return result;
    }
};