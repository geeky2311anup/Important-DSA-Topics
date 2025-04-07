#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << (y * x) / 100 << endl;
    }
    return 0;
}