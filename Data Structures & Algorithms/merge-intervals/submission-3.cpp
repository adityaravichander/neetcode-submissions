class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


        /*
        pseudo code:

         l1 = intervals[i][0]
         r1 = intervals[i][1]
         l2 = intervals[i+1][0]
         r2 = intervals[i+1][1]
        
        if r1 >= l2:
            delete [l1,r1]
            update [l2, r2] as [l1, r2]
            i+=2
        else:
            
            i+=2


        */

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        int l1 = 0; 
        int r1 = 0;
        int l2 = 0;
        int r2 = 0;

        for(auto& interval: intervals)
        {
            int start = interval[0];
            int end = interval[1];
            int lastEnd = mergedIntervals.back()[1];

            if(start <= lastEnd)
            {
                mergedIntervals.back()[1] = max(lastEnd, end);
            }
            else
            {
                mergedIntervals.push_back({start, end});
            }

        }
        return mergedIntervals;
    }
};
