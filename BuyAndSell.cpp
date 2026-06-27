#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
        
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    Solution sol;
    cout<<"Max Profit is "<<sol.maxProfit(prices)<<endl;
    return 0;
}