#include <unordered_map>
#include <map>

using namespace std;

 long long n = nums.size();
    long long totalPairs = (n * (n - 1)) / 2; 
    unordered_map<int, long long> freq;
    long long goodPairs = 0;

    for (int i = 0; i < n; i++) {
        int value = nums[i] - i;
        goodPairs += freq[value]; 
        freq[value]++; 
    }

    return totalPairs - goodPairs;