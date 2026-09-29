class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m = nums.size()-1;

        return (nums[m]*nums[m-1] - nums[0]*nums[1]);
    }
};