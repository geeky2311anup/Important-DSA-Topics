#include <unordered_map>

using namespace std;

class Solution {
    public:
        void backtrack(unordered_map<char, int>& freq, int& count) {
        for (auto& [ch, f] : freq) {
            if (f > 0) {
                
                count++;
                freq[ch]--; 
    
                
                backtrack(freq, count);
    
                
                freq[ch]++;
            }
        }
    }
    
        int numTilePossibilities(string tiles) {
            unordered_map<char, int> freq;
        
        
        for (char c : tiles) {
            freq[c]++;
        }
    
        int count = 0;
        backtrack(freq, count);
        return count;
        }
    };