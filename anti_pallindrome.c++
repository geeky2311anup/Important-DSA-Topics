#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>


int main() {
    // Fast I/O for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;   // number of test cases

    while (t--) {
        int n;
        cin >> n;   // length of the string

        string s;
        cin >> s;   // input string

        // Map to store frequency of each character
        unordered_map<char, int> freq;

        // Count frequency of each character in the string
        for (char c : s) {
            freq[c]++;
        }

        int odds = 0;

        // Count how many characters have odd frequency
        for (auto &p : freq) {
            if (p.second % 2 != 0) {
                odds++;
            }
        }

        // Case 1: length of string is even
        if (n % 2 == 0) {

            // If all characters have even frequency
            // one palindrome is possible
            if (odds == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";

        } 
        // Case 2: length of string is odd
        else {

            // If all characters are the same
            // special case gives answer 2
            if (freq.size() == 1)
                cout << 2 << "\n";

            // If exactly one character has odd frequency
            // one palindrome possible
            else if (odds == 1)
                cout << 1 << "\n";

            // Otherwise no valid arrangement
            else
                cout << 0 << "\n";
        }
    }

    return 0;
}
