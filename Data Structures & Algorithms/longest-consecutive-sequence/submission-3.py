class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        if not nums:
            return 0

        maxLength = 1
        curLength = 1
        for i,n in enumerate(nums):
            if i+1 < len(nums):
                if nums[i+1] == n + 1:
                    curLength +=1 
                elif nums[i+1] == n:
                    continue
                else:
                    curLength = 1

                maxLength = max(maxLength, curLength)
        return maxLength


            



        