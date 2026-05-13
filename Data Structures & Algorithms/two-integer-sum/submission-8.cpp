class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // LOGIC
        /* 
                Scan entire array. 
                Every current value, check if there is a value when added is target
                Next value can only be successor. C not P. 
                Assumption: Only one pair. Makes it easy. 

                Best solution: O(n) Hashmap 
                Middle: O(nlogn) Two pointers
                Brute Force: O(n^2) Two FOR
        */ 
        
        // BRUTE FORCE
        cout << nums.size();
        for(int i = 0;  i<= nums.size(); i++)
            {
                for(int j = i+1; j <= nums.size()-1; j++)
                {
                    if(nums[j] == target - nums[i])
                        return {i,j};
                }
            }
        return {};
        
    }
};
