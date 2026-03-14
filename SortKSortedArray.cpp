#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> sortNearlySortedArray(vector<int>& arr, int k){
            vector<int> res;
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int i=0;i<=k;i++) pq.push(arr[i]);

            for(int i=k+1;i<arr.size();i++){
                res.push_back(pq.top());
                pq.pop();
                pq.push(arr[i]);
            }
            while(!pq.empty()){
                res.push_back(pq.top());
                pq.pop();
            }
            return res;
        }
};

int main(){
    Solution sol;
    int n,k;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    cout<<"Enter the value of k "<<endl;
    cin>>k;
    vector<int> arr(n);
    cout<<"Enter the values of array"<<endl;
    for(int& it:arr) cin>>it;
    vector<int> ans = sol.sortNearlySortedArray(arr,k);

    cout<<"Sorted array is: ";
    for(int x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;

}