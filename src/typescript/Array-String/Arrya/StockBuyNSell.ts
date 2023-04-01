// leetcode : 121. https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

function maxProfit(prices: number[]): number {
    let left = 0,
        right = 0;
    let profit = 0;

    for (let i = 0; i < prices.length; i++) {
        if (prices[left] > prices[i]) {
            left = i;
            right = i;
        }

        if (prices[right] < prices[i]) right = i;

        console.log(prices[left], prices[right]);

        if (prices[right] - prices[left] > profit) profit = prices[left] - prices[right];
    }
    return profit;
}

maxProfit([7, 1, 5, 3, 6, 4]);
