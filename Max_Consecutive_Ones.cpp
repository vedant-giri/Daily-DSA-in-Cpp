#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int longestOnes(vector<int>& nums,int k){
            int l=0;
            int maxlen=0;
            int zeros=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    zeros++;
                }
                if(zeros>k){
                    if(nums[l]==0){
                        zeros--;
                    }
                    l++;
                }
                maxlen=max(maxlen,i-l+1);
                

            }
            return maxlen;
        }
};

int main(){
    Solution sol;
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> nums(n);
    for(int &it:nums) cin>>it;
    cout<<"Longest ones are "<<sol.longestOnes(nums,k)<<endl;
    return 0;
}