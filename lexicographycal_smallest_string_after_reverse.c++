class Solution {
public:
    string fun(string s){
        int m=s.length();
        for(int i=0,j=m-1;i<j;i++,j--){
            swap(s[i],s[j]);
        }
        return s;
    }
    string lexSmallest(string s) {
        int n=s.length();
        string ans = s;
       for(int i=1;i<=n;i++){
           string s1=s.substr(0,i);
           string s2 = s.substr(i,n-i);
           string s1rev = fun(s1);
           string s2rev = fun(s2);
           string srev1= s1rev+ s2;
           string srev2= s1+s2rev;
           
           if(srev1<ans){
               ans=srev1;
           }
           if(srev2<ans){
               ans = srev2;
           }
           
           
       }
        return ans;
    }
};
