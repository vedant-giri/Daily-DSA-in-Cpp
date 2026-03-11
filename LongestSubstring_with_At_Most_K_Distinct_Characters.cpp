#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lengthOfLongestSubstringKDistinct(string s,int k){
        if(k==0 || s.empty()) return 0;
        int maxlen=0;
        unordered_map<char,int> mp;
        int l=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};

int main(){
    Solution sol;
    string s;
    int k;
    cout<<"Enter string: "<<endl;
    cin>>s;
    cout<<"Enter value of k: "<<endl;
    cin>>k;
    cout<<"Length of Longest Substring is "<<sol.lengthOfLongestSubstringKDistinct(s,k)<<endl;
    return 0;
}