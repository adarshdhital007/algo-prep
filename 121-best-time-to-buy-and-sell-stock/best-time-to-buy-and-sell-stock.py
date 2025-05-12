class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        min_price = prices[0]
        best = 0

        for i in range(n):
            min_price = min(min_price, prices[i])
            best = max(best, prices[i] - min_price)
        return best
