class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int count=0;
        for(int i=n-1;i>=0;i--){
          if(isalpha(s[i])){
            while(isalpha(s[i])){
                count++;
                i--;
                if(i<0){
                    break;
                }
            }
            break;
          }
        }
        return count;
    }
};