#include <algorithm>
#include <string>
using namespace std;

class Solution {
    public:
        bool reorderedPowerOf2(int n) {
            string sig = to_string(n);
            sort(sig.begin(), sig.end());
    
            for (int i = 0; i <= 30; i++) { // 2^30 > 1e9
                int pow2 = 1 << i;
                string temp = to_string(pow2);
                sort(temp.begin(), temp.end());
                if (temp == sig) return true;
            }
            return false;
        }
    };
    