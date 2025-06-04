#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        unordered_set<int> uniqueElements;
        
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            uniqueElements.insert(num);
        }
        
        cout << uniqueElements.size() << endl;
    }

    return 0;
}