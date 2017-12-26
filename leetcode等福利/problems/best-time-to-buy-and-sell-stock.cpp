/******************************************************
* problem id : 121
* problem title : Best Time to Buy and Sell Stock
* problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*******************************************************/

/* Enumeration algorithm, O(n^2) */
int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int ans[size][size];
    int max = INT_MIN;

    for(int i=0; i<size-1; i++)
        for(int j=i+1; j<size; j++)
            ans[i][j] = prices[j] - prices[i];

    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if(ans[i][j]>max)
                max = ans[i][j];
        }
    }

    return max;
}

/* O(n) solution */
int maxProfit(vector<int>& prices) {
    int size = prices.size(), min, max_profit=0;

    if(size==0)
        return 0;
    min = prices[0];
    for(int i=1; i<size; i++) {
        if(prices[i]>=min)
            max_profit = max(max_profit, prices[i]-min);
        else
            min = prices[i];
    }

    return max_profit;
}
