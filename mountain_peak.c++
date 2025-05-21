#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // Not strictly needed for this code, but often useful with vectors

using namespace std;

vector<int> next_higher_peak(vector<int>& heights) {
    int n = heights.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[i] > heights[st.top()]) {
            int idx = st.top();
            st.pop();
            result[idx] = heights[i];
        }
        st.push(i);
    }

    return result;
}

int main() {
    int n;
    
    cin >> n;

    vector<int> heights(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    vector<int> result = next_higher_peak(heights);

    for (int height : result) {
        cout << height << " ";
    }
    cout << endl;

    return 0;
}