class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        /* I'll need to scan the entire array from the beginning
        current value and next value. 
        for every current value check if there is a next value when added is target
        and this next value can only be successsor because combination and not permutation. 

        assumption: only one pair satisfies condition... makes it simple

        */

        int i = 0;
        int j = 1;

        // how can we optimize 

        vector<pair<int,int>> valueIndexPair;

        for(int index = 0; index < nums.size(); index++)
         {
            valueIndexPair.push_back({nums[index], index});
         }

        sort(valueIndexPair.begin(), valueIndexPair.end());

        int currentIndex = 0, nextIndex = nums.size() - 1;

        while (currentIndex < nextIndex)
        {
            int currentSum = valueIndexPair[currentIndex].first + valueIndexPair[nextIndex].first;

            if(currentSum == target)
            {
                return
                    {
                        min(valueIndexPair[currentIndex].second, valueIndexPair[nextIndex].second),
                        max(valueIndexPair[currentIndex].second, valueIndexPair[nextIndex].second)
                    };
            }
            else if (currentSum < target)
            {
                currentIndex++;
            }
            else
            {
                nextIndex--;
            }


        }

        return {};


        // O(n^2) high time complexity - not optimal solution - brute force solution


        // for(i=0; j<=length-1;i++)
        // {
        //     cout << "\n i= " << i << " \n";
        //     for(j=i+1;j<=nums.size()-1;j++)
        //     {
        //         cout << "j = " << j << ",";
        //         if(nums[j] == target - nums[i])
        //         {
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};        
    }
};
