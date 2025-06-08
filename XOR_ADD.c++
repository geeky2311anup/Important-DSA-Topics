#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        for (int start = 1; start <= 9; ++start) {
            generateLexicalNumbers(start, n, lexicographicalNumbers);
        }
        return lexicographicalNumbers;
    }

private:
    void generateLexicalNumbers(int currentNumber, int limit,
                                vector<int>& result) {
        if (currentNumber > limit) return;

        result.push_back(currentNumber);

        for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currentNumber * 10 + nextDigit;
            if (nextNumber <= limit) {
                generateLexicalNumbers(nextNumber, limit, result);
            } else {
                break;
            }
        }
    }
};

int main() {
    Solution sol;
    int n1 = 13;
    vector<int> result1 = sol.lexicalOrder(n1);
    cout << "Lexical order up to " << n1 << ": ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    int n2 = 25;
    vector<int> result2 = sol.lexicalOrder(n2);
    cout << "Lexical order up to " << n2 << ": ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
