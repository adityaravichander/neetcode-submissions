from collections import defaultdict
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        itemFreq = defaultdict(int)

        for n in nums:
            itemFreq[n]+=1
        
        heap = []

        for item, freq in itemFreq.items():
            heapq.heappush(heap, (freq, item))

            if len(heap) > k:
                heapq.heappop(heap)


        return [ item for freq, item in sorted(heap, reverse=True) ]
            


        
        