#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int KthLargestElement(vector<int>& nums,int k){
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int i=0;i<k;i++){
                pq.push(nums[i]);
            }
            for(int i=k;i<nums.size();i++){
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            return pq.top();
        }

};

int main(){
    Solution sol;
    int n,k;
    cout<<"Enter value of k"<<endl;
    cin>>k;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter values of array"<<endl;
    for(int& it:nums) cin>>it;
    cout<<"Kth largest element is "<<sol.KthLargestElement(nums,k)<<endl;
    return 0;
}