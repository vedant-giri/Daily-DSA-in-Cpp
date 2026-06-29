#include <bits/stdc++.h>
using namespace std;

// Solution class for LIS with reconstruction using DP
class Solution {
public:
    // Function to return the LIS as a sequence (vector)
    vector<int> longestIncreasingSubsequence(vector<int> &nums) {
        int n = nums.size();

        // DP array to store length of LIS ending at each index
        vector<int> dp(n, 1);

        // Array to store previous index of LIS element for reconstruction
        vector<int> prev(n, -1);

        // Compute LIS length for each index
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    // Update dp[i] and store previous index
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        // Find the index of maximum LIS length
        int maxLen = 0, maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }

        // Reconstruct LIS sequence
        vector<int> lisSeq;
        int curr = maxIndex;
        while (curr != -1) {
            lisSeq.push_back(nums[curr]);
            curr = prev[curr];
        }

        // Reverse sequence as it was built backwards
        reverse(lisSeq.begin(), lisSeq.end());

        return lisSeq;
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution sol;
    vector<int> lis = sol.longestIncreasingSubsequence(nums);

    cout << "LIS: ";
    for (int x : lis) cout << x << " ";
    cout << endl;

    return 0;
}
