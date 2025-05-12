#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
    
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> evenNumbers;
        int n = digits.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || i == k) {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0) {
                        evenNumbers.insert(num);
                    }
                }
            }
        }

        vector<int> result(evenNumbers.begin(), evenNumbers.end());
        return result;
    }
};
