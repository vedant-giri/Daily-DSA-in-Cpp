#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int ind, string &s,
               unordered_set<string> &st,
               vector<int> &dp) {
        if (ind == s.size())
            return true;

        if (dp[ind] != -1)
            return dp[ind];

        string temp = "";

        for (int i = ind; i < s.size(); i++) {
            temp += s[i];

            if (st.count(temp)) {
                if (solve(i + 1, s, st, dp))
                    return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }

    bool wordBreak(string &s, vector<string> &dictionary) {
        unordered_set<string> st(dictionary.begin(),
                                 dictionary.end());

        vector<int> dp(s.size(), -1);

        return solve(0, s, st, dp);
    }
};

int main() {
    int n;
    cin >> n;  // number of words in dictionary

    vector<string> dictionary(n);
    for (int i = 0; i < n; i++) {
        cin >> dictionary[i];
    }

    string s;
    cin >> s;

    Solution obj;

    if (obj.wordBreak(s, dictionary))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}