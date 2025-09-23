#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;
#include <string>


// Function to convert a word to title case
string convertToTitleCase(const string& word) {
    string result = "";
    for (int i = 0; i < word.length(); i++) {
        if (i == 0)
            result += toupper(word[i]);  // Capitalize the first letter
        else
            result += tolower(word[i]);  // Convert the rest to lowercase
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // Consume the newline character after reading T

    for (int t = 0; t < T; t++) {
        string S;
        getline(cin, S);

        istringstream iss(S);
        string word;
        bool firstWord = true;

        while (iss >> word) {
            if (!firstWord) {
                cout << " ";
            }
            firstWord = false;

            // Check if the word is an acronym (entirely in uppercase)
            bool isAcronym = true;
            for (char c : word) {
                if (!isupper(c)) {
                    isAcronym = false;
                    break;
                }
            }

            if (isAcronym) {
                cout << word;  // If it's an acronym, print as is
            } else {
                cout << convertToTitleCase(word);  // Convert to title case
            }
        }

        cout << endl;
    }

    return 0;
}