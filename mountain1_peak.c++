#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Function to find the next greater element (peak) for each element
vector<int> next_higher_peak(vector<int>& heights) {
    int n = heights.size();

    // Initialize result array with -1 (default if no greater element exists)
    vector<int> result(n, -1);

    // Stack will store indices of elements
    stack<int> st;

    // Traverse through the array
    for (int i = 0; i < n; ++i) {

        // While current element is greater than the element
        // corresponding to index at the top of the stack
        while (!st.empty() && heights[i] > heights[st.top()]) {
            int idx = st.top();  // Get index from stack
            st.pop();            // Remove it

            // Assign current element as next greater for that index
            result[idx] = heights[i];
        }

        // Push current index onto the stack
        st.push(i);
    }

    // Remaining elements in stack do not have a next greater element
    // (they remain -1)

    return result;
}

int main() {
    int n;

    // Read size of the array
    cin >> n;

    vector<int> heights(n);

    // Input array elements
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    // Call function to compute next higher peaks
    vector<int> result = next_higher_peak(heights);

    // Output the result
    for (int height : result) {
        cout << height << " ";
    }

    cout << endl;

    return 0;
}
