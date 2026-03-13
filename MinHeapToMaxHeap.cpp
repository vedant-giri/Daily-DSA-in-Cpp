#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l < n && arr[l] > arr[largest])
            largest = l;

        if(r < n && arr[r] > arr[largest])
            largest = r;

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void buildMaxHeap(vector<int>& arr, int n) {
        for(int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
};

int main() {

    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter array elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    obj.buildMaxHeap(arr, n);

    cout<<"Max Heap array:\n";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}