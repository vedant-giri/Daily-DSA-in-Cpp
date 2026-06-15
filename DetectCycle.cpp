#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool detectCycle(int V,vector<vector<int>>& adj){
            vector<int> visited(V);

            for(int i=0;i<V;i++){
                if(!visited[i]){
                    if(dfs(visited,adj,i,-1)) return  true;
                }
            }
            return false;
        }
        bool dfs(vector<int>& visited,vector<vector<int>>& adj,int node,int parent){
            visited[node]=1;
            for(int& ngb:adj[node]){
                if(!visited[ngb]){
                    if(dfs(visited,adj,ngb,node)) return true;
                }else if(parent!=ngb) return true;
            }
            return false;
        }

};

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution sol;
    bool ans=sol.detectCycle(V,adj);
    if(ans){
        cout<<"True"<<endl;
    }else cout<<"False"<<endl;

    return 0;
}