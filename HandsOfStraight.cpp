#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isNStraightHand(vector<int>& hand,int groupSize){
        if(hand.size() % groupSize !=0) return false;

        map<int,int> freq;
        for(int it:hand) freq[it]++;

        auto it=freq.begin();
        while(it!=freq.end()){
            if(it->second ==0){
                ++it;
                continue;
            }

            int start=it->first;
            int count=it->second;

            for(int i=0;i<groupSize;i++){
                if(freq[start+i]<count) return false;
                freq[start+i]-=count;
            }

            ++it;
        }
        return true;
    }
};

int main(){
    Solution sol;
    int n,groupSize;

    cout<<"Enter the size of group: ";
    cin>>groupSize;

    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> hand(n);

    for(auto &it : hand) cin >> it;

    cout<<sol.isNStraightHand(hand,groupSize)<<endl;

    return 0;
}