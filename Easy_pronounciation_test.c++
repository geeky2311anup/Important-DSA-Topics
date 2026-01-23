#include <iostream>
#include <string>
using namespace std;

// Function to check whether a character is a lowercase vowel
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int T;
    cin >> T;  // Number of test cases
    
    // Loop through each test case
    while (T--) {
        int N;
        cin >> N;   // Length of the string (not strictly needed, but provided)
        
        string S;
        cin >> S;   // Input string
        
        int consecutive = 0;  // Counts consecutive consonants
        bool easy = true;     // Flag to determine if string is "easy"
        
        // Iterate through each character in the string
        for (char c : S) {
            if (!isVowel(c)) {
                // If character is a consonant, increment counter
                consecutive++;
                
                // If 4 or more consecutive consonants are found
                if (consecutive >= 4) {
                    easy = false;
                    break;  // No need to check further
                }
            } else {
                // Reset counter when a vowel is found
                consecutive = 0;
            }
        }
        
        // Output result for the current test case
        cout << (easy ? "YES" : "NO") << endl;
    }
    
    return 0;  // End of program
}
