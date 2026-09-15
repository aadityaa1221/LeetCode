class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0;
        int cntr = 0;

        for(char c : s){
            if(c == 'R') cntr++;
            else cntr--;
            if(cntr == 0) cnt++;
        }

        return cnt;
    }
};