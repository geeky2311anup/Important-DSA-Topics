#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int add, int shift) {
        
        unordered_set<string> seen;   // Stores all visited strings to avoid repetition
        deque<string> dq;             // Queue for BFS traversal
        string smallest = s;          // Track lexicographically smallest string
        int len = s.size();           // Length of string

        dq.push_back(s);              // Start BFS with initial string
        seen.insert(s);               // Mark initial string as visited

        while (!dq.empty()) {
            string cur = move(dq.front()); // Get current string
            dq.pop_front();

            // Update smallest if current is lexicographically smaller
            if (cur < smallest) smallest = cur;

            // -------- Operation 1: Add to odd indices --------
            string withAdd = cur;
            for (int i = 1; i < len; i += 2) {
                int d = withAdd[i] - '0';   // Convert char to digit
                d = (d + add) % 10;         // Add and wrap around (mod 10)
                withAdd[i] = char('0' + d); // Convert back to char
            }

            // If new string not seen before, push to queue
            if (seen.emplace(withAdd).second) 
                dq.push_back(withAdd);

            // -------- Operation 2: Rotate string --------
            string rotated = cur;
            rotate(rotated.begin(), rotated.end() - shift, rotated.end());
            // This rotates string to the right by 'shift'

            // If new string not seen before, push to queue
            if (seen.emplace(rotated).second) 
                dq.push_back(rotated);
        }

        return smallest; // Final answer
    }
};
