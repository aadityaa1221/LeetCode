class Solution {
public:
    void dfs(int k, vector<vector<int>> &graph, vector<bool> &vis){
        vis[k] = true;

        for(auto i : graph[k]){
            if(!vis[i]){
                dfs(i, graph, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for(auto i : invocations){
            graph[i[0]].push_back(i[1]);
        }
        vector<bool> vis(n, false);
        dfs(k, graph, vis);

        for (auto &edge : invocations) {
            if (!vis[edge[0]] && vis[edge[1]]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }


        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};