class Solution {
    public int maxProfit(int[] prices) {
        int startingPrice = prices[0];
        int highestPrice = 0;

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > startingPrice) {
                highestPrice = Math.max(highestPrice, prices[i] - startingPrice);
            } else {
                startingPrice = prices[i];
            }
        }
        return highestPrice;

    }
}