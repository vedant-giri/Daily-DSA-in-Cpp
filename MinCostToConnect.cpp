#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int minCost(vector<int>& arr){
            priority_queue<int,vector<int>,greater<>> pq;
            for(int it:arr) pq.push(it);
            int totalCost=0;
            while(pq.size()>1){
                int x=pq.top();
                pq.pop();
                int y=pq.top();
                pq.pop();
                int cost=x+y;
                totalCost+=cost;
                pq.push(cost);
            }
            return totalCost;
        }
};

int main(){
    Solution sol;
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    vector<int> arr(n);
    for(int& it:arr) cin>>it;
    cout<<"Minimum cost to connect is "<<sol.minCost(arr)<<endl;
    return 0;
}