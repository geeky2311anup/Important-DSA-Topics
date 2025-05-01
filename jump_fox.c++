#include <iostream>
#include <string>
#include <stack>

bool isValidParenthesis(const std::string &s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        std::string S;
        std::cin >> S;
        std::cout << (isValidParenthesis(S) ? 1 : 0) << std::endl;
    }
    return 0;
}