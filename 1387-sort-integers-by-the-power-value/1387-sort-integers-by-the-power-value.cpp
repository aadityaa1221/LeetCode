class Solution {
public:
    unordered_map<int, int> mp;

    int power(int x) {
        if (x == 1) return 0;
        if (mp.count(x)) return mp[x];

        if (x % 2 == 0) return mp[x] = 1 + power(x / 2);
        else return mp[x] = 1 + power(3 * x + 1);
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> nums;

        for (int x = lo; x <= hi; x++) {
            nums.push_back({power(x), x});
        }
       
        sort(nums.begin(), nums.end());
        return nums[k - 1].second;
    }
};
