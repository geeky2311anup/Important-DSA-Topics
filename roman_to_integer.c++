class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;

         int ans=0;
         int n=s.length();
         
         
         mp['I']=  1;
         mp['V']=  5;
         mp['X']=  10;
         mp['L']=  50;
         mp['C']=  100;
         mp['D']=  500;
         mp['M']=  1000;
         char curr=s[0];
         char next=s[0];
         if(n==1){
        return mp[s[0]];
         }
        for(int i=1;i<n;i++){
            next=s[i];
            curr=s[i-1];
            if(mp[curr]>=mp[next]){
                ans=ans+mp[curr];
                if(i==n-1){
                    ans=ans+mp[next];
                }
            }
            else{
                ans=ans+(mp[next]-mp[curr]);
                i++;
                if(i==n-1){
                    ans=ans+mp[s[i]];
                }
               

            }
            
        }
        return ans;
    }
};