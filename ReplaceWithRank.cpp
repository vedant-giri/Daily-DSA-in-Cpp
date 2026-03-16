#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> replaceWithRank(vector<int> &arr, int N){
            vector<int> temp=arr;
            sort(temp.begin(),temp.end());
            unordered_map<int,int> mp;
            int rank=1;
            for(int it:temp){
                if(mp.count(it)==0){
                    mp[it]=rank;
                    rank++;
                }
            }
            vector<int> res;
            for(int i=0;i<N;i++){
                res.push_back(mp[arr[i]]);
            }
            return res;
        }
};

int main(){
    Solution sol;
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the values of array:"<<endl;
    for(int& it:arr) cin>>it;
    vector<int> res=sol.replaceWithRank(arr,n);
    for(int it:res) cout<<it<<" ";
    cout<<""<<endl;
    return 0;
}
