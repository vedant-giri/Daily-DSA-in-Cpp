#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int numberOfSubarrays(vector<int>& nums,int k){
            return atMostFreq(nums,k)-atMostFreq(nums,k-1);
        }
        int atMostFreq(vector<int>& nums,int k){
            int l=0;
            int oddCount=0;
            int res=0;

            for(int r=0;r<nums.size();r++){
                if(nums[r]%2 != 0){
                    oddCount++;
                } 

                while(oddCount>k){
                    if(nums[l]%2 !=0) oddCount--;
                    l++;
                }
                res+=(r-l+1);
            }
            return res;
        }
};

int main(){
    Solution sol;
    int n,k;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter "<<n<<" values of array"<<endl;
    for(int &num:nums) cin>>num;
    cout<<"Enter value of K: "<<endl;
    cin>>k;
    cout<<"Number of subarrays are "<<sol.numberOfSubarrays(nums,k)<<endl;
    return 0;
}
