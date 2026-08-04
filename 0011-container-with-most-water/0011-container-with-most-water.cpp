class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while(left < right){
            int w = right - left;
            int h = min(height[left], height[right]);
            int curr_area = w * h;

            max_area = max(max_area, curr_area);

            if(height[left] < height[right]) left++;
            else right--;
        }

        return max_area;
    }
};