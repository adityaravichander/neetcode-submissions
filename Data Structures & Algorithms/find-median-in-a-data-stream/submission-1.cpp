class MedianFinder {
    //vector<int> data;
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;


public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // solution 1 - sort
        // data.push_back(num);


        // solution 2 - heap
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top())
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > largeHeap.size()+1)
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1)
        {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {

        // solution 2 -- heap / prio queue

        if(smallHeap.size() == largeHeap.size())
        {
            return (largeHeap.top() + smallHeap.top())/2.0;
        }
        else if(smallHeap.size() > largeHeap.size())
        {
            return smallHeap.top();
        }
        else
        {
            return largeHeap.top();
        }


        // solution 1 -- sorting 
        // time =  O(m*nlogn), m - function calls
        /* 
        sort(data.begin(), data.end());
        int n = data.size();
        if (n & 1)
        {
            return data[n / 2];
        }
        else
        {
            return (data[n / 2] + data[n / 2 - 1]) / 2.0;
        }
        */

    }
};
