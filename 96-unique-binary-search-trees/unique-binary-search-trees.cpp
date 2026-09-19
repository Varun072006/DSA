class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int left = 0; left < i; ++left) {
                int right = i - left - 1;
                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n];
    }
};