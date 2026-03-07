#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int totalFruits(vector<int>& fruits){
        int maxlen,l;
        maxlen=0;
        l=0;
        unordered_map<int,int> mp;
        for(int r=0;r<fruits.size();r++){
            mp[fruits[r]]++;

            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};

int main(){\
    Solution sol;
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    vector<int> fruits(n);
    cout<<"Enter values of array: "<<endl;
    for(int &it:fruits) cin>>it;
    cout<<"Total Fruits are "<<sol.totalFruits(fruits)<<endl;
    return 0;
}