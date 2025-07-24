
class Solution {
    public:
      // Function to find the minimum number of coins to make the change
      // for value using the coins of given denominations.
      long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value) {
          // your code here
          vector<long long>dp(value+1,-1);
          int n=numberOfCoins;
          dp[0]=0;
          for(int i=0;i<n;i++){
              for(int j=1;j<=value;j++){
                  if((j-coins[i])>=0){
                      if(dp[j-coins[i]]!=-1){
                          if(dp[j]==-1){
                             dp[j]=dp[j-coins[i]]+1;
                          }
                          else{
                              dp[j]=min(dp[j],dp[j-coins[i]]+1);
                          }
                      
                      }
                    
                  }
              }
          }
          return dp[value];
          
      }
  };