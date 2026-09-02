class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[arr[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int first = arr[j] - arr[i];

                if(mp.count(first) && mp[first] < i){
                    int k = mp[first];

                    dp[i][j] = dp[k][i] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans >= 3 ? ans : 0;
    }
};