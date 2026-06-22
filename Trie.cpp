#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[2] = {nullptr, nullptr};

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxXor;
    }
};

vector<int> maximizeXor(vector<int>& nums,
                        vector<vector<int>>& queries) {

    sort(nums.begin(), nums.end());

    int q = queries.size();

    vector<pair<int, pair<int, int>>> offlineQueries;

    for (int i = 0; i < q; i++) {
        // {m, {x, original index}}
        offlineQueries.push_back(
            {queries[i][1], {queries[i][0], i}}
        );
    }

    sort(offlineQueries.begin(), offlineQueries.end());

    vector<int> ans(q, -1);

    Trie trie;

    int idx = 0;
    int n = nums.size();

    for (auto &query : offlineQueries) {

        int m = query.first;
        int x = query.second.first;
        int originalIdx = query.second.second;

        while (idx < n && nums[idx] <= m) {
            trie.insert(nums[idx]);
            idx++;
        }

        if (idx == 0) {
            ans[originalIdx] = -1;
        } else {
            ans[originalIdx] = trie.getMax(x);
        }
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter size of nums: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of nums: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    cout << "Enter queries as (x m):\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = maximizeXor(nums, queries);

    cout << "\nAnswers:\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}