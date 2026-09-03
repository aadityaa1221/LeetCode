class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn_odd = INT_MAX;

        for(int i : nums1){
            if(i % 2 == 1){
                mn_odd = min(mn_odd, i);
            }
        }

        if(mn_odd == INT_MAX) return true;
        for(int i : nums1){
            if(i % 2 == 0 && i < mn_odd) return false; 
        } 
        return true;
    }
};