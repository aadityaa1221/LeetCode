class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;

        for(auto &l : logs){
            mp[l[0]].insert(l[1]);
        }

        vector<int> ans(k, 0);

        for(auto &[user, min] : mp){
            int UAM = min.size();

            if(UAM <= k){
                ans[UAM - 1]++;
            }
        }

        return ans;
    }
};