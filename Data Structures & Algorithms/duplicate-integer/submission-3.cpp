class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

// hash maps method
// add value and count to hashmap

    // unordered_map<int, int> valueCount; 

    // for(int i = 0; i < nums.size(); i++)
    // {
    //     int number = nums[i];
    //     if(valueCount.count(number))
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         valueCount[nums[i]]++;
    //     }
    // }
    // return false;
    // }

// Sorting / Two pointer method

        sort(nums.begin(), nums.end());
        int currentIndex = 0;
        while(currentIndex < nums.size())
        {
    //         cout << "\n current index = " << currentIndex;
    //         cout << "\n ----current value = " << nums[currentIndex];
    //         cout << "\n nextIndex = " << nextIndex;
    //         cout << "\n ----next value = " << nums[nextIndex];
            if(nums[currentIndex]==nums[currentIndex-1])
            {
                return true;
            }
            currentIndex++;
        }
        return false;
    }
    // }
};