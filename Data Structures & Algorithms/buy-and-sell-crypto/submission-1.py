class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        # start time = 10:10 pm
        # end time = 10:12 pm
        l = 0
        r = 1
        maxProfit = 0
        while(r < len(prices)):
            if prices[l] < prices[r]:
                profit = prices[r] - prices[l]
                maxProfit = max(maxProfit, profit)
            else:
                l = r
            r += 1

        return maxProfit
        
        