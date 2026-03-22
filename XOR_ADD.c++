#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Class that contains the solution
class Solution {
public:
    // Function to return numbers from 1 to n in lexicographical (dictionary) order
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers; // Stores the final result

        // Start generating numbers from 1 to 9
        for (int start = 1; start <= 9; ++start) {
            generateLexicalNumbers(start, n, lexicographicalNumbers);
        }

        return lexicographicalNumbers;
    }

private:
    // Recursive helper function to generate numbers in lexicographical order
    void generateLexicalNumbers(int currentNumber, int limit,
                                vector<int>& result) {
        // If current number exceeds the limit, stop recursion
        if (currentNumber > limit) return;

        // Add the current number to the result
        result.push_back(currentNumber);

        // Try appending digits 0 to 9 to the current number
        for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currentNumber * 10 + nextDigit;

            // If the new number is within the limit, continue recursion
            if (nextNumber <= limit) {
                generateLexicalNumbers(nextNumber, limit, result);
            } else {
                // If it exceeds the limit, no need to check further digits
                break;
            }
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 13;
    vector<int> result1 = sol.lexicalOrder(n1);

    cout << "Lexical order up to " << n1 << ": ";
    // Print all numbers in lexicographical order
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    int n2 = 25;
    vector<int> result2 = sol.lexicalOrder(n2);

    cout << "Lexical order up to " << n2 << ": ";
    // Print all numbers in lexicographical order
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
