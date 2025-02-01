class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0){
            return false;
        }
        else{
            long long temp=static_cast<long long>(x);
          long long rev=0;
            while(temp>0){
                rev=rev*10+ temp%10;
                    temp=temp/10;
            }
            return x==rev;
        }
    }
};