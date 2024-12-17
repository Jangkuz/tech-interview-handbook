
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0;  // No profit can be obtained with less than two prices
    }

    // int minPrice = prices[0];
    int maxProfit = 0;
    int minIndex = 0;
    // int maxIndex = 0;

    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] < prices[minIndex]) {
            minIndex = i;  // Update the minimum price
        } else {
            
            if (prices[i] - prices[minIndex] > maxProfit) {
                maxProfit = prices[i] - prices[minIndex];  // Update the maximum profit
            }
        }
    }

    return maxProfit;
}

int main(){
    int prices[] = {7,2,4,8,2,3,6,0};
    int arraySize = sizeof(prices)/sizeof(prices[0]);
    int result = maxProfit(prices, 10);
    printf("%d\n", result);
}