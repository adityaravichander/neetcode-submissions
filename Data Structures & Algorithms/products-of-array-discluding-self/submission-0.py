class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        prod = 1
        zeroCount = 0
        for n in nums:
            if n:
                prod = prod * n
            else:
                zeroCount+=1
        
        if zeroCount > 1:
            return [0] * len(nums)
        
        result = [0] * len(nums)

        for i, c in enumerate(nums):
            if zeroCount:
                if c:
                    result[i] = 0
                else:
                    result[i] = prod
            else:
                result[i] = prod // c
        
        return result
        