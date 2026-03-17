#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);

        for(char task : tasks){
            freq[task - 'A']++;
        }
        priority_queue<int> maxHeap;

        for(int f : freq){
            if(f > 0){
                maxHeap.push(f);
            }
        }

        int time = 0;
        while(!maxHeap.empty()){

            int cycle = n + 1;
            int i = 0;

            vector<int> temp;

            while(i < cycle && !maxHeap.empty()){

                int cnt = maxHeap.top();
                maxHeap.pop();

                cnt--;

                if(cnt > 0){
                    temp.push_back(cnt);
                }

                time++;
                i++;
            }
            for(int val : temp){
                maxHeap.push(val);
            }
            if(maxHeap.empty())
                break;
            time += (cycle - i);
        }

        return time;
    }
};

int main(){

    Solution obj;

    vector<char> tasks = {'A','A','A','B','B','B'};

    int n = 2;

    int result = obj.leastInterval(tasks, n);

    cout << "Minimum CPU intervals required: " << result << endl;

    return 0;
}