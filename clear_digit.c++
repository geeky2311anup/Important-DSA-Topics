#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i]) && !st.empty() ){
                    st.pop();
                    
            }
            else if(islower(s[i])){
                st.push(s[i]);
            }
        }
        while(!st.empty()){
              ans=string(1,st.top())+ans;
              st.pop();
        }
        return ans;
    }
};