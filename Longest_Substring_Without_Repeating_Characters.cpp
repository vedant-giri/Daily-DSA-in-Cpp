#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxlen = 0;
        int l = 0;   // right pointer
        int r = 0;   // left pointer

        while (l < s.length()) {
            if (!st.count(s[l])) {
                st.insert(s[l]);
                maxlen = max(maxlen, l - r + 1);
                l++;
            } 
            else {
                st.erase(s[r]);
                r++;
            }
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    
    cout << sol.lengthOfLongestSubstring(s) << endl;
    
    return 0;
}