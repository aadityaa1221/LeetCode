class Solution {
private:
    string ans = "";
    int k;
public:
    void solve(int n, string &s){
        if(ans != "") return;

        if(s.size() == n){
            k--;
            if(k == 0) ans = s;
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!s.empty() && ch == s.back()) continue;

            s.push_back(ch);
            solve(n, s);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        this->k = k;

        string s = "";
        solve(n, s);
        return ans;
    }
};