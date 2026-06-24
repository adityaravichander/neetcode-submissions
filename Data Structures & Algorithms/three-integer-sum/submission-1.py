class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        # nums[i] + nums[j] + nums[k] = 0
        # same as two sum
        # nums[j] + nums[k] = - nums[i]
        nums.sort()
        result = []
        for i in range(0, len(nums)):
            l = i+1
            r = len(nums) - 1
            while(l < r):
                target = -nums[i]
                if nums[l] + nums[r] == target:
                    if [nums[i], nums[l], nums[r]] not in result:
                        result.append([nums[i], nums[l], nums[r]])
                    l+=1
                elif nums[l] + nums[r] > target:
                    r-=1
                elif nums[l] + nums[r] < target:
                    l+=1

        return result