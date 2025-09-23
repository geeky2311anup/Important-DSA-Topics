#include <string>
#include <stack>

using namespace std;

int n = pattern.size();
stack<int> st;
string result = "";

for (int i = 0; i <= n; i++) {
    st.push(i + 1);  // Push numbers from 1 to n+1

    // When we reach the end or see an 'I', pop all from the stack
    if (i == n || pattern[i] == 'I') {
        while (!st.empty()) {
            result += to_string(st.top());
            st.pop();
        }
    }
}

return result;