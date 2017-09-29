class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int N = prices.size();
        
        for (int start = 0; start < N; ) {
            int l = start;  // Low index
            while (l < N-1 && prices[l] >= prices[l+1]) l++;  // Find the lowest prices.
            int h = l;      // High index
            while (h < N-1 && prices[h] <= prices[h+1]) h++;  // Find the highest prices.
            
            maxProf += prices[h] - prices[l];
            
            start = h + 1;
        }
        return maxProf;
    }
};