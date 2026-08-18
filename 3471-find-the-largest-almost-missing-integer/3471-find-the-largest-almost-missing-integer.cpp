class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(51, 0);
        for(int i : nums) cnt[i]++;

        if(k == n) return *max_element(nums.begin(), nums.end());
        if(k == 1){
            int ans = -1;

            for(int i : nums){
                if(cnt[i] == 1){
                    ans = max(ans, i);
                }
            }

            return ans;
        }

        int ans = -1;
        if(cnt[nums[0]] == 1){
            ans = max(ans, nums[0]);
        }
        if(cnt[nums[n - 1]] == 1){
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};