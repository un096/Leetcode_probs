#include <vector>

class Solution {
    public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> ans(k, 0);
        std::vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;
            std::vector<long long> next_dp(k, 0);

            // Single-element subarray starting and ending at current index
            next_dp[val]++;

            // Extend all subarrays ending at the previous index
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * val) % k] += dp[r];
                }
            }
            
            // Accumulate counts for each remainder
            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return ans;
    }
};
            