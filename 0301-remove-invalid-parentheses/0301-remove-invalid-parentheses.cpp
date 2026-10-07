class Solution {
public:
    vector<string> ans;

    bool isValid(string &s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }

        return balance == 0;
    }

    void dfs(string &s, int start, int left, int right) {
        if (left == 0 && right == 0) {
            if (isValid(s)) ans.push_back(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {

            if (i > start && s[i] == s[i - 1]) continue;
            if (left + right > s.size() - i) return;

            if (left > 0 && s[i] == '(') {
                s.erase(i, 1);
                dfs(s, i, left - 1, right);
                s.insert(i, 1, '(');
            }

            else if (right > 0 && s[i] == ')') {
                s.erase(i, 1);
                dfs(s, i, left, right - 1);
                s.insert(i, 1, ')');
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();

        int left = 0;
        int right = 0;

        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }

        dfs(s, 0, left, right);
        return ans;
    }
};