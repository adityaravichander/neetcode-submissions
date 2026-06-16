class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:

        # 9:45 pm - start time
        # 9:47 pm - end time
        # hashmap , if already in it, return true

        n_map = {}

        for i, n in enumerate(nums):
            if n in n_map:
                return True
            else:
                n_map[n] = i

        return False