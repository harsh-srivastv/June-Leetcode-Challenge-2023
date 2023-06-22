class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            /*
            cash[i] = cash[i-1]: do nothing
            cash[i] = hold+prices[i]-fee: sell the stock held in last day
            */
            cash = max(cash, hold + prices[i] - fee);
            /*
            hold[i] = hold[i-1]: do nothing
            hold = cash[i-1] - prices[i]: buy stock today
            */
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};