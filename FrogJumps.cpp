#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum cost to reach index 'ind' using at most 'k' jumps
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
    // Base case: starting point has zero cost
    if (ind == 0) return 0;

    // Return already computed result
    if (dp[ind] != -1) return dp[ind];

    // Initialize minimum steps as large value
    int mmSteps = INT_MAX;

    // Try all possible jumps from 1 to k
    for (int j = 1; j <= k; j++) {
        // Ensure jump does not go out of bounds
        if (ind - j >= 0) {
            // Cost of taking the jump
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            // Store the minimum cost
            mmSteps = min(jump, mmSteps);
        }
    }
    // Save the result in dp array
    return dp[ind] = mmSteps;
}

// Function to get minimum cost to reach end
int solve(int n, vector<int>& height, int k) {
    // DP array initialized to -1
    vector<int> dp(n, -1);
    // Start recursion from last index
    return solveUtil(n - 1, height, dp, k);
}

// Driver code
int main() {
    // Heights of stones
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;

    // Output the minimum cost
    cout << solve(n, height, k) << endl;
    return 0;
}
