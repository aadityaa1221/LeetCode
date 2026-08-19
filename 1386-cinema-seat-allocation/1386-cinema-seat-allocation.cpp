class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &r : reservedSeats) {
            int row = r[0];
            int col = r[1];
            mp[row] |= (1 << (col - 1));
        }

        int ans = (n - mp.size()) * 2;

        int leftMask   = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
        int middleMask = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
        int rightMask  = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);

        for (auto &[row, mask] : mp) {
            bool left = (mask & leftMask) == 0;
            bool middle = (mask & middleMask) == 0;
            bool right = (mask & rightMask) == 0;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};