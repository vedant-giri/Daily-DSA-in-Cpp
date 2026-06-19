#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int spanningTree(int V,vector<vector<pair<int,int>>>& adj){
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int wt=it.first;
            pq.pop();
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjWt=it.second;
                if(!vis[adjNode]){
                    pq.push({adjWt,adjNode});
                }
            }
        }
        return sum;
    }
};
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int,int>>> adj(V);

    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    Solution sol;
    cout<<sol.spanningTree(V,adj)<<endl;
    return 0;
}