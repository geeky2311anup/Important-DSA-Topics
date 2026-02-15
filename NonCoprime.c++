#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        for(int i=0;i<nums.size();){
                 if(st.empty()){
                    st.push(nums[i]);
                    i++;
                 }
                 else{
                    int t=st.top();
                    if(gcd(nums[i],t)>1){
                        int l = (int)((1ll*nums[i]*t)/gcd(nums[i],t));
                        st.pop();
                        nums[i]=l;

                    }
                    else{
                        st.push(nums[i]);
                        i++;
                    }
                 }
        }
        vector<int> result;
       while(!st.empty()){
        result.push_back(st.top());
        st.pop();
       }
        reverse(result.begin(), result.end());
       return result;
    }
};
