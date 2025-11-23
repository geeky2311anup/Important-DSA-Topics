#include <vector>

using namespace std;

class Solution {
  public:
    // Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n) {

        // your code herevector
        vector<int> dp(n,-1);
        dp[0]=0;
        if(arr[0]==0){
            return -1;
        }
         int k=0;
        for(int i=1;i<n;i++){
            for( int j=k;j<i;j++){
                if(arr[j]>=(i-j)){
                    dp[i]=dp[j]+1;
                    k=j;
                    break;
                }
            }
        }
        return dp[n-1];
        
        
    }
};
