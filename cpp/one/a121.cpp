class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int mp = prices[0],  // min point
            profit = 0;
        for (int i = 1; i < n; i++)
            if (prices[i] < mp)
                mp = prices[i];
            else
                profit = max (profit, prices[i] - mp);
        
        return profit;
    }
};