class Solution {
public:
    int minimumDeletions(string word, int k) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> cnt;
        for (auto &ch : word) {
            cnt[ch]++;
        }

        // Initialize result with maximum possible deletions
        // (in worst case, delete the entire string)
        int res = word.size();

        // Step 2: Try each character frequency as the base frequency 'a'
        for (auto &[_, a] : cnt) {

            // Track how many deletions are needed for this base frequency
            int deleted = 0;

            // Compare with every other character frequency 'b'
            for (auto &[_, b] : cnt) {

                // Case 1:
                // If current frequency b is smaller than base a,
                // we must delete all occurrences of this character
                if (a > b) {
                    deleted += b;
                }
                // Case 2:
                // If frequency b is too large (exceeds allowed range a + k),
                // delete the extra characters
                else if (b > a + k) {
                    deleted += b - (a + k);
                }
                // Otherwise, b is within the allowed range → no deletion needed
            }

            // Update the minimum deletions found so far
            res = min(res, deleted);
        }

        // Return the minimum deletions required
        return res;
    }
};
