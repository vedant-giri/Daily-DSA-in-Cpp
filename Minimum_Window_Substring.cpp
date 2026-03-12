#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size() < t.size()) return "";

        vector<int> freq(128, 0);

        // Store frequency of characters of t
        for(char c : t) {
            freq[c]++;
        }

        int left = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {

            if(freq[s[right]] > 0)
                count--;

            freq[s[right]]--;

            // When valid window found
            while(count == 0) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};

int main() {

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    Solution obj;
    string result = obj.minWindow(s, t);

    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}