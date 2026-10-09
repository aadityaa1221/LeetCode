class Solution {
public:
    int minInsertions(string s) {
        int open = 0, ans = 0, i = 0;

        while(i < s.length()){
            if(s[i] == '('){
                open++;
                i++;
            }else{
                if(i + 1 < s.length() && s[i + 1] == ')'){
                    i += 2;
                }else{
                    ans++;
                    i++;
                }

                if(open > 0){
                    open--;
                }else{
                    ans++;
                }
            }
        }

        ans += 2 * open;
        return ans;
    }
};