#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int characterReplacement(string s,int k){
            vector<int> hash(26,0);
            int freq=0;
            int l=0;
            int len=0;
            for(int r=0;r<s.size();r++){
                hash[s[r]-'A']++;
                freq=max(freq,hash[s[r]-'A']);
                while((r-l+1)-freq>k){
                    hash[s[l]-'A']--;
                    l++;
                }
                len=max(len,r-l+1);
                
            }
            return len;
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
    cout<<"Length of longest string is "<<sol.characterReplacement(s,k)<<endl;
    return 0;
}