class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        numberIndex = dict()
        ans = [] 
        for i in range(0, len(nums)):
            if target - nums[i] in numberIndex:
                print("test1")
                minIndex = min(numberIndex[target-nums[i]], i)
                maxIndex = max(numberIndex[target-nums[i]], i)
                ans = [minIndex, maxIndex]

            else:
                print("test2")
                numberIndex[nums[i]] = i
        print(numberIndex)
        return ans
        