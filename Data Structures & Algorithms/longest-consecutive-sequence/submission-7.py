class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        if not nums:
            return 0
        result = 0
        current = nums[0]
        streak = 0
        i = 0

        while i < len(nums):
            if current != nums[i]:
                current = nums[i]
                streak = 0
            
            # check duplicates
            while i < len(nums) and nums[i] == current:
                i+=1

            # back to normal  
            streak += 1
            current += 1
            result = max(result, streak)

        # maxLength = 1
        # curLength = 1
        # for i,n in enumerate(nums):
        #     if i+1 < len(nums):
        #         if nums[i+1] == n + 1:
        #             curLength +=1 
        #         elif nums[i+1] == n:
        #             continue
        #         else:
        #             curLength = 1
        #         maxLength = max(maxLength, curLength)
        return result


            



        