class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int high=INT_MIN;
        int low=INT_MAX;
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
              

            if(prices[i]<low){
                low=prices[i];
                high=INT_MIN;
            }
            if(prices[i]>high){
                high=prices[i];
            }
              profit=max(profit,high-low);
        }
        return profit;

    }
};