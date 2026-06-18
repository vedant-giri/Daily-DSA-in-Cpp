#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {

        vector<vector<int>> adj(N);

        // Build graph
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // Undirected graph
        }

        vector<int> dist(N, 1e9);

        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);

        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9)
                ans[i] = dist[i];
        }

        return ans;
    }
};

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int src;
    cin >> src;

    Solution obj;

    vector<int> ans = obj.shortestPath(edges, N, M, src);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}