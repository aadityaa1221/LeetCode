class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(m + 1, n);
        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                suf[j] = i;
                j--;
            }
        }

        vector<int> ans;
        int pos = 0;
        bool miss = false;

        for (int j = 0; j < m; j++) {
            bool found = false;

            while (pos < n) {
                if (word1[pos] == word2[j]) {
                    ans.push_back(pos);
                    pos++;
                    found = true;
                    break;
                }
                else if (!miss) {
                    if (j == m - 1 || (suf[j + 1] != n && suf[j + 1] > pos)) {
                        ans.push_back(pos);
                        pos++;
                        miss = true;
                        found = true;
                        break;
                    }
                }
                pos++;
            }
            if (!found) return {};
        }

        return ans;
    }
};