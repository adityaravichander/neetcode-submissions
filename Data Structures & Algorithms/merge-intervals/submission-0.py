class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals.sort(key=lambda i: i[0])

        ans = [intervals[0]]

        lastj = intervals[0][1]

        for i, j in intervals[1:]:
            lastj = ans[-1][1]
            if i <= lastj:
                ans[-1][1] = max(lastj,j)
            else:
                ans.append([i,j])
        
        return ans

        