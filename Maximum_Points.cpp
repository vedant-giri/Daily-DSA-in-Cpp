#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxScore(vector<int>& nums,int k){
            int sum=0;
            int maxScore=0;
            for(int i=0;i<k;i++){
                sum+=nums[i];
            }
            maxScore=sum;

            for(int i=0;i<k;i++){
                sum-=nums[k-1-i];
                sum+=nums[nums.size()-1-i];
                maxScore=max(maxScore,sum);
            }
            return maxScore;
        }
};
int main(){
    Solution sol;
    int n,k;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the values of array"<<endl;
    for(int &num:nums) cin>>num;
    cout<<"Enter the value of k:"<<endl;
    cin>>k;
    cout<<"Maximum points are "<<sol.maxScore(nums,k)<<endl;
    return 0;
}