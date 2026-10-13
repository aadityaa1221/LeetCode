class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int mid = n / 2;

        for(int &i : nums){
            i = i * i;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < mid; i++){
            ans -= nums[i];
        }

        for(int i = mid; i < n; i++){
            ans += nums[i];
        }

        return ans;
    }
};