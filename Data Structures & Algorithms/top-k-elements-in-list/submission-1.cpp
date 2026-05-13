class Solution {
public:
    vector<int> topKFrequent(vector<int>& n, int k) {

        unordered_map<int,int> itemFreq;
        for (int i = 0; i < n.size(); i++)
        {
            itemFreq[n[i]]+=1;
        }

        using Element = pair<int, int>;
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;

        for (const auto& pair: itemFreq)
        {
            minHeap.push({pair.second, pair.first});
            if(minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> result;
        while(!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
