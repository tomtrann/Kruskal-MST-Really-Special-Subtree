class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);

        // build extended nums
        for (int i = 0; i < n; i++)
            arr[i + 1] = nums[i];

        n += 2;  // account for added boundaries

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length of the interval
        for (int len = 2; len < n; len++) {
            for (int left = 0; left + len < n; left++) {
                int right = left + len;

                // choose last balloon to burst between (left, right)
                for (int k = left + 1; k < right; k++) {
                    dp[left][right] = max(dp[left][right],
                        arr[left] * arr[k] * arr[right]
                        + dp[left][k]
                        + dp[k][right]
                    );
                }
            }
        }

        return dp[0][n - 1];
    }
};
