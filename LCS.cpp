#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string &text1, string &text2,
              vector<vector<int>> &dp) {
        // Base case
        if (i == 0 || j == 0)
            return 0;

        // If already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match
        if (text1[i - 1] == text2[j - 1]) {
            return dp[i][j] =
                1 + solve(i - 1, j - 1, text1, text2, dp);
        }

        // If characters don't match
        return dp[i][j] =
            max(solve(i - 1, j, text1, text2, dp),
                solve(i, j - 1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, text1, text2, dp);
    }
};

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    Solution obj;
    int ans = obj.longestCommonSubsequence(text1, text2);

    cout << "Length of LCS = " << ans << endl;

    return 0;
}