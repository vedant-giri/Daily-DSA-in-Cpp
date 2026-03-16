#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Comparator for Min Heap
class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Insert first node of each list into heap
        for (auto list : lists) {
            if (list)
                pq.push(list);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next)
                pq.push(smallest->next);
        }

        return dummy->next;
    }
};

// Function to create linked list from user input
ListNode* createList(int n) {

    if (n == 0) return nullptr;

    int val;
    cin >> val;

    ListNode* head = new ListNode(val);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    return head;
}

// Function to print linked list
void printList(ListNode* head) {

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    int k;
    cout << "Enter number of linked lists: ";
    cin >> k;

    vector<ListNode*> lists(k);

    for (int i = 0; i < k; i++) {

        int n;
        cout << "Enter number of elements in list " << i + 1 << ": ";
        cin >> n;

        cout << "Enter elements of sorted list " << i + 1 << ": ";
        lists[i] = createList(n);
    }

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    cout << "Merged Sorted List: ";
    printList(result);

    return 0;
}