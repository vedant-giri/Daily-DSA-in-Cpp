#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int,int> mp;
        for(int num : nums)
            mp[num]++;

        // Step 2: Min-heap — C++11/14 compatible
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(auto& entry : mp){
            minHeap.push({entry.second, entry.first});
            if(minHeap.size() > k)
                minHeap.pop();
        }

        // Step 3: Collect results
        vector<int> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = sol.topKFrequent(nums1, k1);
    cout << "Test 1: ";
    for(int x : result1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = sol.topKFrequent(nums2, k2);
    cout << "Test 2: ";
    for(int x : result2) cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> nums3 = {4, 4, 4, 6, 6, 7, 7, 7, 7, 8};
    int k3 = 3;
    vector<int> result3 = sol.topKFrequent(nums3, k3);
    cout << "Test 3: ";
    for(int x : result3) cout << x << " ";
    cout << endl;

    // Test Case 4
    vector<int> nums4 = {-1, -1, 2, 2, 2, 3};
    int k4 = 2;
    vector<int> result4 = sol.topKFrequent(nums4, k4);
    cout << "Test 4: ";
    for(int x : result4) cout << x << " ";
    cout << endl;

    return 0;
}