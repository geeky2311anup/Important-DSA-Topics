class Solution {
    public:
             int is_palindrome(string &s,int i,int j,vector<vector<int>> &dp){
            if(i>=j){return 1;}
            if(s[i]!=s[j]){return 0;}
            if(dp[i][j]!=-1){return dp[i][j];}
            dp[i][j]=is_palindrome(s,i+1,j-1,dp);
            return dp[i][j];
    
        }
       
        
           
        string longestPalindrome(string s) {
            int max=0;
            int start_ind=0;
            string temp="";
            
            int n=s.length();
            vector<vector<int>> dp(n,vector<int>(n,-1));
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                  if(is_palindrome(s,i,j,dp)){
                         if((j-i+1)>max){
                            max=j-1+1;
                          start_ind=i;
    
                         }
                  } 
                    
                }
            }
            return s.substr(start_ind,max);
        }
    };