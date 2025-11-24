#include <string>

using namespace std;

class Solution {
    private:
    int count = 0;   
    string result = "";  

    void generateHappyString(int n, string curr, char prev, int &k) {
        if (curr.length() == n) {  
            count++;
            if (count == k) { 
                result = curr;
            }
            return;
        }
        
        for (char c : {'a', 'b', 'c'}) { 
            if (c != prev) {  
                generateHappyString(n, curr + c, c, k);
                if (!result.empty()) return;  
            }
        }
    }
public:
 

    string getHappyString(int n, int k) {
             count = 0;
        result = "";
        generateHappyString(n, "", '\0', k); 
        return result;  
    }
    
};