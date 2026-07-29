class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            bool f = false, s = false;

            for(int j = i + 1; j < n; j++){
                if(nums[j] - nums[i] == diff){
                    f = true;
                }
                if(nums[j] - nums[i] == 2 * diff){
                    s = true;
                }
            }

            if(f && s) ans++;
        }

        return ans;
    }
};