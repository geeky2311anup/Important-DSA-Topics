class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum){
            return "";
        }
        string ans(num,'0');
     
        
        for(int i=0;i<num;i++){
            if(sum==0){
                break;
            }
            for(int j=9;j>=0;j--){
                if(sum>=j){
                    ans[i] = '0'+j;
                    sum=sum-j;
                    break;
                }
            }
        }
        return ans;
    }   
    
};
