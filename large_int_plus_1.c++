class Solution {
public:
   bool is_nine(vector<int> v){
            int n=v.size();
            for(int i=0;i<n;i++){
                if(v[i]!=9){
                    return false;
                }
            }
            return true;
   }
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]<9){
           digits[n-1]=digits[n-1]+1;
        }
        else if(is_nine(digits)){
            digits.push_back(0);
            digits[0]=1;
            for(int i=1;i<n+1;i++){
                    digits[i]=0;
            }
        }
        else{
            int temp=0;
            int carry=1;
            
                
            for(int i=n-1;i>=0;i--){
                temp=digits[i]+carry;
               digits[i]=(temp)%10;
               if(temp==10){
                carry=1;
               }
               else{
                carry=0;
               }
               
            }
        
        }
       return digits;

    }
};