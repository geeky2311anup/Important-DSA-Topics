#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        
        int consecutive = 0;
        bool easy = true;
        
        for (char c : S) {
            if (!isVowel(c)) {
                consecutive++;
                if (consecutive >= 4) {
                    easy = false;
                    break;
                }
            } else {
                consecutive = 0;
            }
        }
        
        cout << (easy ? "YES" : "NO") << endl;
    }
    
    return 0;
}

