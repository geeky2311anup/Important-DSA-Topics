#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int diff = y - x;
        int wins = ceil((double)diff / 8);
        cout << wins << endl;
    }
    return 0;
}