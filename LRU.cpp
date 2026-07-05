#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of frames: ";
    cin >> capacity;

    vector<int> frames;
    unordered_map<int, int> lastUsed;

    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        bool found = false;
        for (int x : frames) {
            if (x == page) {
                found = true;
                break;
            }
        }

        // Page Hit
        if (found) {
            lastUsed[page] = i;
        }
        // Page Fault
        else {
            pageFaults++;

            if (frames.size() < capacity) {
                frames.push_back(page);
            } else {
                // Find least recently used page
                int lruPage = frames[0];
                int minIndex = lastUsed[lruPage];

                for (int x : frames) {
                    if (lastUsed[x] < minIndex) {
                        minIndex = lastUsed[x];
                        lruPage = x;
                    }
                }

                // Replace LRU page
                for (int j = 0; j < frames.size(); j++) {
                    if (frames[j] == lruPage) {
                        frames[j] = page;
                        break;
                    }
                }
            }

            lastUsed[page] = i;
        }

        // Display frames
        cout << "After page " << page << ": ";
        for (int x : frames)
            cout << x << " ";
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << pageFaults << endl;

    return 0;
}