class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int N = prices.size();
        if (N <= 1) return 0;
        
        // One transaction profits.
        vector<int> leftProfits(N, 0), rightProfits(N, 0);
        
        // One transaction profit from left to right.
        for (int i = 1, l = 0, h = 0; i < N; i++) {
            if (prices[i] > prices[h])
                h = i;
            else if (prices[i] < prices[l]) {
                h = l = i;
            }
            leftProfits[i] = max(leftProfits[i-1], prices[h] - prices[l]);
        }
        
        // One transaction profit from right to left.
        for (int i = N-2, l = N-1, h = N-1; i >= 0; i--) {
            if (prices[i] < prices[l])
                l = i;
            else if (prices[i] > prices[h]) {
                l = h = i;
            }
            rightProfits[i] = max(rightProfits[i+1], prices[h] - prices[l]);
        }
        
        // Split prices into two transaction. Sum of left trans and right trans.
        for (int i = 1; i < N-1; i++)
            maxProf = max(maxProf, leftProfits[i] + rightProfits[i+1]);
        
        return max(maxProf, leftProfits[N-1]);  // You can only do one transaction.
    }
    
};