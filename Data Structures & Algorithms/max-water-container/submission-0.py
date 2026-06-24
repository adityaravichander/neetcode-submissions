class Solution:
    def maxArea(self, heights: List[int]) -> int:

        l = 0
        r = len(heights) - 1
        max_area = 0

        # for max amount of water --- area of container should be max
        # for maxArea -- max width x max height
        # max(r-l) and max(min_height)

        while l<r:
            area = min(heights[l], heights[r]) * (r-l)
            max_area = max(max_area, area)

            if heights[l] <= heights[r]:
                l+=1
            else:
                r-=1
        
        return max_area
 

        