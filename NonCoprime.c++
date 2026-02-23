class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;   // Stack to store processed elements
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); ) {

            // If stack is empty, push current element
            if (st.empty()) {
                st.push(nums[i]);
                i++;
            } 
            else {
                int topElement = st.top();

                // Check if current number and top of stack are not coprime
                // (i.e., gcd > 1 means they share a common factor)
                if (gcd(nums[i], topElement) > 1) {

                    // Compute LCM using formula:
                    // lcm(a, b) = (a * b) / gcd(a, b)
                    long long lcmValue = (1LL * nums[i] * topElement) / gcd(nums[i], topElement);

                    // Remove the top element because it will be merged
                    st.pop();

                    // Replace current number with LCM
                    // We DO NOT increment i here because
                    // the new LCM might still merge with new stack top
                    nums[i] = (int)lcmValue;
                }
                else {
                    // If they are coprime, just push current element
                    st.push(nums[i]);
                    i++;
                }
            }
        }

        // Transfer stack elements to result vector
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // Since stack gives reversed order, reverse to restore original order
        reverse(result.begin(), result.end());

        return result;
    }
};
