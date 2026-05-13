class Solution {
public:

// recursion
int binary_search(int l, int r, vector<int>& nums, int target)
{
    if(l > r) return -1;
    int m = l + (r-l)/2;

    if (nums[m] == target) return m;
    return ((nums[m]) < target) ? binary_search(m+1, r, nums, target) : binary_search(l, m-1, nums, target);
}
int search(vector<int>&nums, int target)
{
    return binary_search(0, nums.size()-1, nums, target);
}

// iterative search
    // int search(vector<int>& nums, int target) {
    //     int l = 0, r = nums.size() - 1;

    //     while (l <= r) {
    //         int m = l + ((r - l) / 2);
    //         if (nums[m] > target) {
    //             r = m - 1;
    //         } else if (nums[m] < target) {
    //             l = m + 1;
    //         } else {
    //             return m;
    //         }
    //     }
    //     return -1;
    // }
};