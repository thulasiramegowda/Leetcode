int maxProfit(int* prices, int pricesSize) {

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {

        // Find the cheapest price seen so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Calculate profit if we sell today
        int profit = prices[i] - minPrice;

        // Keep the best profit
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}