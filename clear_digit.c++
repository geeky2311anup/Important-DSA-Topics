class Solution {
public:
    string clearDigits(string s) {
        // A stack is used to keep track of characters that haven't been "cleared" yet.
        stack<char> st;
        string ans = "";
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            // If the current character is a digit and we have characters to remove,
            // we pop the top of the stack (deleting the closest non-digit to the left).
            if(isdigit(s[i]) && !st.empty()){
                st.pop();
            }
            // If it's a lowercase letter, we push it onto the stack as a potential survivor.
            else if(islower(s[i])){
                st.push(s[i]);
            }
        }
        
        // After processing the whole string, the stack contains the remaining characters.
        // We extract them to build the final result string.
        while(!st.empty()){
            // Note: Since a stack is Last-In-First-Out (LIFO), 
            // adding st.top() to the front of the string preserves the original order.
            ans = string(1, st.top()) + ans;
            st.pop();
        }
        
        return ans;
    }
};
