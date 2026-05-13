class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

// hash maps method
// add value and count to hashmap

    unordered_map<int, int> valueCount; 

    for(int i = 0; i < nums.size(); i++)
    {
        int number = nums[i];
        if(valueCount.count(number))
        {
            return true;
        }
        else
        {
            valueCount[nums[i]]++;
        }
    }
    return false;
    }

// Two pointer method

    //     sort(nums.begin(), nums.end());
    //     cout << "length of sorted nums = " << nums.size();
    //     int currentIndex = 0, nextIndex = nums.size() - 1;
    //     while(currentIndex < nextIndex)
    //     {
    //         cout << "\n current index = " << currentIndex;
    //         cout << "\n ----current value = " << nums[currentIndex];
    //         cout << "\n nextIndex = " << nextIndex;
    //         cout << "\n ----next value = " << nums[nextIndex];


    //         if(nums[currentIndex]==nums[nextIndex])
    //         {
    //             return true;
    //         }
    //         else if(nums[currentIndex] < nums[nextIndex])
    //         {
    //             currentIndex++;
    //         }
    //         else
    //         {
    //             nextIndex--;
    //         }
    //     }
    //     return false;
    // }
};