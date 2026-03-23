#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {

        if(nums1.empty() || nums2.empty() || k <= 0) return {};

        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        priority_queue<tuple<int, int, int>> maxHeap;
        set<pair<int, int>> visited;

        maxHeap.push(make_tuple(nums1[0] + nums2[0], 0, 0));  // ✅ make_tuple
        visited.insert(make_pair(0, 0));                       // ✅ make_pair

        vector<int> result;

        while(k-- && !maxHeap.empty()) {

            // ✅ get<>() instead of structured bindings
            int sum = get<0>(maxHeap.top());
            int i   = get<1>(maxHeap.top());
            int j   = get<2>(maxHeap.top());
            maxHeap.pop();

            result.push_back(sum);

            if(i + 1 < (int)nums1.size() && !visited.count(make_pair(i+1, j))) {
                maxHeap.push(make_tuple(nums1[i+1] + nums2[j], i+1, j));
                visited.insert(make_pair(i+1, j));
            }

            if(j + 1 < (int)nums2.size() && !visited.count(make_pair(i, j+1))) {
                maxHeap.push(make_tuple(nums1[i] + nums2[j+1], i, j+1));
                visited.insert(make_pair(i, j+1));
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    int n1, n2, k;
    cout << "Enter size of nums1: "; cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter elements of nums1: ";
    for(int i = 0; i < n1; i++) cin >> nums1[i];

    cout << "Enter size of nums2: "; cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter elements of nums2: ";
    for(int i = 0; i < n2; i++) cin >> nums2[i];

    cout << "Enter k: "; cin >> k;

    vector<int> result = sol.maxCombinations(nums1, nums2, k);

    cout << "Top " << k << " maximum sum combinations: ";
    for(int val : result) cout << val << " ";
    cout << endl;

    return 0;
}