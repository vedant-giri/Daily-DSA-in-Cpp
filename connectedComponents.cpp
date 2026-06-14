#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int connectedComponents(int V,vector<vector<int>>& edges){
            vector<vector<int>> adj(V);
            for(auto& e:edges){
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            vector<int> visited(V,0);
            int cnt=0;
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    cnt++;
                    queue<int> q;
                    q.push(i);
                    visited[i]=1;
                    while(!q.empty()){
                        int node=q.front();
                        q.pop();
                        for(int &it:adj[node]){
                            if(!visited[it]){
                                q.push(it);
                                visited[it]=1;
                            }
                        }
                    }
                }
            }
            return cnt;
        }
};
int main(){
    int V,E;
    cin>>V>>E;

    vector<vector<int>> edges;

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    Solution sol;
    cout<<"Number of connected components are "<<sol.connectedComponents(V,edges)<<endl;
    return 0;
}
