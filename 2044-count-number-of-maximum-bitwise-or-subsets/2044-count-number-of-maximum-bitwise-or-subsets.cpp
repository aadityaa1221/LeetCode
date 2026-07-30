class Solution {
public:
    int target, ans;
    void dfs(vector<int> &nums, int idx, int curr){
        if(idx == nums.size()){
            if(curr == target) ans++;
            return;
        }

        dfs(nums, idx + 1, curr | nums[idx]);
        dfs(nums, idx + 1, curr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        target = 0;
        ans = 0;
        for(int i : nums) target |= i;

        dfs(nums, 0, 0);
        return ans;
    }
};