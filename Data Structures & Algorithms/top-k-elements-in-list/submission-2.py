class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
                            # solution 1 - sorting - N log n
        # count = {}
        # for n in nums:
        #     count[n] = 1 + count.get(n,0)
        # arr = []
        # for n, c in count.items():
        #     arr.append([c,n])
        # arr.sort()
        # answer = []
        # while len(answer) < k:
        #     answer.append(arr.pop()[1])
        # return answer
                            # solution 2 - heap
        count = {}
        for n in nums:
            count[n] = 1 + count.get(n,0)

        heap = []

        for n in count.keys():
            heapq.heappush(heap, (count[n], n))
            if len(heap) > k:
                heapq.heappop(heap)
        
        topFreq = []
        for i in range(k):
            topFreq.append(heapq.heappop(heap)[1])
        return topFreq


