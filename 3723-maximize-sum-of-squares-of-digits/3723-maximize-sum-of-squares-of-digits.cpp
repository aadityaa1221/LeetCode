class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        int nines = sum / 9;
        int r = sum % 9;

        string ans(nines, '9');

        if (r > 0) {
            ans += char('0' + r);
        }

        ans += string(num - ans.size(), '0');

        return ans;
    }
};