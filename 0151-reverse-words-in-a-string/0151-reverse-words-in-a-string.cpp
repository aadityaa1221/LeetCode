class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int idx = 0, n = s.size();

        for(int i = 0; i < n;){
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            if(idx != 0) s[idx++] = ' ';

            int start = idx;
            while(i < n && s[i] != ' ')s[idx++] = s[i++];
            reverse(s.begin() + start, s.begin() + idx);
        }
        s.resize(idx);
        return s;
    }
};