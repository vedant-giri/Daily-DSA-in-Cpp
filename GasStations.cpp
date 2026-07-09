#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long double minimizeMaxDistance(vector<int>& arr, int k) {
        int n = arr.size();

        // howMany[i] = number of gas stations inserted in interval i
        vector<int> howMany(n - 1, 0);

        // {current maximum section length, interval index}
        priority_queue<pair<long double, int>> pq;

        // Initially every interval has one section
        for (int i = 0; i < n - 1; i++) {
            pq.push({(long double)(arr[i + 1] - arr[i]), i});
        }

        // Place k gas stations
        for (int i = 0; i < k; i++) {

            auto it = pq.top();
            pq.pop();

            int idx = it.second;

            // Add one more station in this interval
            howMany[idx]++;

            long double originalLength = (long double)(arr[idx + 1] - arr[idx]);

            // Interval is divided into (howMany[idx] + 1) parts
            long double newSectionLength =
                originalLength / (howMany[idx] + 1);

            pq.push({newSectionLength, idx});
        }

        return pq.top().first;
    }
};

int main() {

    Solution sol;

    cout << "Enter value of N\n";
    int N;
    cin >> N;

    vector<int> arr(N);

    cout << "Enter the values of array\n";
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int k;

    cout << "Enter the value of k\n";
    cin >> k;

    cout << fixed << setprecision(6)
         << sol.minimizeMaxDistance(arr, k);

    return 0;
}