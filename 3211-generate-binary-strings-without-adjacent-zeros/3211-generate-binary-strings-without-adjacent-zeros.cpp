class Solution {
public:
    vector<string> ans;

    void solve(string &s, int n){
        if(s.length() == n){
            ans.push_back(s);
            return;
        }

        s.push_back('1');
        solve(s, n);
        s.pop_back();

        if(s.empty() || s.back() != '0'){
           s.push_back('0');
           solve(s, n);
           s.pop_back(); 
        }
    }
    vector<string> validStrings(int n) {
        string s = "";
        solve(s, n);
        return ans;
    }
};