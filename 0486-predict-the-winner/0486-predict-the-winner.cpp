class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums);

        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                dp[j] = max(nums[j] - dp[j - 1], nums[i] - dp[j]);
            }
        }

        return dp[n - 1] >= 0;
    }
};