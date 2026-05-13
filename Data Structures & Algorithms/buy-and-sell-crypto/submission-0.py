class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        l, r = 0, 1
        max_profit = 0

        while r < len(prices):
            if prices[l] < prices[r]:
                max_profit = max(max_profit, prices[r] - prices[l])
            else:
                l = r
            r+=1

        return max_profit
        # if prices == []:
        #     return 0
        
        # min_price = prices[0]
        # max_profit = 0

        # for i in range(0, len(prices)):
        #     max_profit = max(max_profit, prices[i] - min_price)
        #     min_price = min(min_price, prices[i])
        
        # return max_profit
        