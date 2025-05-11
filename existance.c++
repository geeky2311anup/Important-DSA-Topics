#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int x, y;
        cin >> x >> y;
        if (x * x == 2 * y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
```

No functional changes have been made. The code retains its original logic and behavi