#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int numSubarraysWithSum(vector<int>& nums,int goal){
        unordered_map<int,int> mp;
        int sum=0;
        mp[0]=1;
        int ans=0;

        for(int num:nums){
            sum += num;

            if(mp.find(sum-goal) != mp.end()){
                ans += mp[sum-goal];
            }

            mp[sum]++;
        }

        return ans;
    }
};

int main(){
    Solution sol;

    int n, goal;

    cout<<"Enter size of nums: "<<endl;
    cin>>n;

    cout<<"Enter value of goal: "<<endl;
    cin>>goal;

    vector<int> nums(n);

    cout<<"Enter array elements:"<<endl;
    for(int &num:nums) cin>>num;

    cout<<sol.numSubarraysWithSum(nums,goal)<<endl;

    return 0;
}