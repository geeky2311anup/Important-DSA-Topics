#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 5;
    
    // Post-Increment Example (i++)
    int x = a++;  // x gets 5, then a becomes 6
    cout << "Post-Increment (i++):" << endl;
    cout << "a: " << a << ", x: " << x << endl;  // a = 6, x = 5

    // Pre-Increment Example (++i)
    int y = ++b;  // b becomes 6 first, then y gets 6
    cout << "\nPre-Increment (++i):" << endl;
    cout << "b: " << b << ", y: " << y << endl;  // b = 6, y = 6

    // Loop Example
    cout << "\nUsing i++ in a loop: ";
    for (int i = 0; i < 5; i++) {  // Post-increment
        cout << i << " ";  // 0 1 2 3 4
    }

    cout << "\nUsing ++i in a loop: ";
    for (int i = 0; i < 5; ++i) {  // Pre-increment
        cout << i << " ";  // 0 1 2 3 4
    }

    return 0;
}




