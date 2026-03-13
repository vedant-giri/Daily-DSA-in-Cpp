#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool check(vector<int>& nums){
            int n=nums.size();
            for(int i=0;i<=(n/2)-1;i++){
                int l=2*i+1;
                if(l<n && nums[l]<nums[i]) return false;
                int r=2*i+2;
                if(r<n && nums[r]<nums[i]) return false;
            }
            return true;
        }
};

int main(){
    Solution sol;
    cout<<"Enter size of array:"<<endl;
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter values of nums arrays:"<<endl;
    for(int &it:nums) cin>>it;
    if(sol.check(nums)) cout<<"Given array is a Heap"<<endl;
    else cout<<"Given array is not a heap"<<endl;
    return 0;
}