class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cnt(26, 0);
        int left = 0;
        int len = 0;

        for(int right = 0; right < s.length(); right++){
            cnt[s[right] - 'a']++;

            while(cnt[s[right] - 'a'] > 2){
                cnt[s[left++] - 'a']--;
            }

            len = max(len, right - left + 1);
        }

        return len;
    }
};