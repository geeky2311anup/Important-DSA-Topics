#include <iostream>   // For input and output (cin, cout)
#include <sstream>    // For string stream (istringstream)
#include <cctype>     // For character functions (toupper, tolower, isupper)
using namespace std;

// Function to convert a word to Title Case
// Example: "hELLo" -> "Hello"
string convertToTitleCase(const string& word) {
    string result = "";

    // Loop through each character of the word
    for (int i = 0; i < word.length(); i++) {

        // Capitalize the first letter
        if (i == 0)
            result += toupper(word[i]);

        // Convert the remaining letters to lowercase
        else
            result += tolower(word[i]);
    }

    // Return the converted word
    return result;
}

int main() {
    int T;

    // Read number of test cases
    cin >> T;

    // Ignore the leftover newline character after reading T
    cin.ignore();

    // Loop through each test case
    for (int t = 0; t < T; t++) {

        string S;

        // Read the full line of text
        getline(cin, S);

        // Create a string stream to split words
        istringstream iss(S);

        string word;

        // Boolean to track if the word is the first in the sentence
        bool firstWord = true;

        // Extract words one by one from the string stream
        while (iss >> word) {

            // Print space before every word except the first one
            if (!firstWord) {
                cout << " ";
            }

            firstWord = false;

            // Assume the word is an acronym initially
            bool isAcronym = true;

            // Check if every character in the word is uppercase
            for (char c : word) {
                if (!isupper(c)) {
                    isAcronym = false;
                    break;
                }
            }

            // If the word is an acronym (all uppercase)
            if (isAcronym) {
                cout << word;   // Print it as it is
            } 
            else {
                // Otherwise convert the word to Title Case
                cout << convertToTitleCase(word);
            }
        }

        // Move to the next line after processing the sentence
        cout << endl;
    }

    return 0;
}
