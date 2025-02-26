#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int unique = 0;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            unique ^= num;
        }
        cout << unique << "\n";
    }
    return 0;
}
