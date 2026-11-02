class Solution {
    vector<vector<int>> adj;
    vector<int> subtree;
    vector<int> ans;
    int N;
    
    void dfs1(int u, int parent, int depth) {
        subtree[u] = 1;
        ans[0] += depth;

        for (int v : adj[u]) {
            if (v == parent) continue;
            dfs1(v, u, depth + 1);
            subtree[u] += subtree[v];
        }
    }

    void dfs2(int u, int parent) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            ans[v] = ans[u] - subtree[v] + (N - subtree[v]);
            dfs2(v, u);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        adj.assign(n, vector<int>());
        subtree.assign(n, 0);
        ans.assign(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs1(0, -1, 0);
        dfs2(0, -1);
        return ans;
    }
};