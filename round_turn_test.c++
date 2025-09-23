#include <iostream>
using namespace std;
#include <string>


void solve() {
    int N, start38 = 0, ltime108 = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string contest;
        cin >> contest;
        if (contest == "START38") start38++;
        else ltime108++;
    }
    
    cout << start38 << " " << ltime108 << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
