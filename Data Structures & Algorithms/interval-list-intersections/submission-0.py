class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:


        ans = []

        i = j = 0

        while i < len(firstList) and j < len(secondList):
            startA, endA = firstList[i]
            startB, endB = secondList[j]

            start = max(startA, startB)
            end = min(endA, endB)

            if start <= end:
                ans.append([start, end])

            if endA < endB:
                i+=1
            else:
                j+=1 
        
        return ans
        
        # for i in range(len(firstList)):
        #     startA = firstList[i][0]
        #     endA = firstList[i][1]

        #     for j in range(len(secondList)):
        #         startB = secondList[j][0]
        #         endB = secondList[j][1]

        #         if startA <= startB <= endA or startB <= startA <= endB:
        #             ans.append([max(startA, startB), min(endA, endB)])

        # return ans


        