class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

        vector<int> dp(n, 1);
        vector<int> order(n);

        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b){
                 return arr[a] < arr[b];
                });

        int ans = 1;

        for (int i : order) {
            
            for (int j = i + 1;
                 j < n && j <= i + d;
                 j++) {

                if (arr[j] >= arr[i])
                    break;

                dp[i] = max(dp[i], 1 + dp[j]);
            }

            for (int j = i - 1;
                 j >= 0 && j >= i - d;
                 j--) {

                if (arr[j] >= arr[i])
                    break;

                dp[i] = max(dp[i], 1 + dp[j]);
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};