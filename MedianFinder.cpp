#include <bits/stdc++.h>
using namespace std;

class MedianFinder{
    private:
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
    public:
        MedianFinder(){

        }
        void addNum(int n){
            maxHeap.push(n);
            minHeap.push(maxHeap.top());
            if(minHeap.size()>maxHeap.size()){
                maxHeap.push(minHeap.top());
            }
        }
        double findMedian(){
            if(minHeap.size()==maxHeap.size()) return (minHeap.top()+maxHeap.top())/2.0 ;
            return  maxHeap.top();
        }
};

int main(){
    
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; 
    mf.addNum(3);
    cout << mf.findMedian() << endl; 
    return 0;
}