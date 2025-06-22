#include <iostream>
#include <string>
using namespace std;

string addOne(string& num) {
    int n = num.length();
    int carry = 1; // we start with a carry of 1
    for (int i = n - 1; i >= 0; i--) {
        int digit = num[i] - '0' + carry;
        num[i] = (digit % 10) + '0';
        carry = digit / 10;
        if (carry == 0) break; // no carry left, break early to save time
    }
    if (carry > 0) {
        num.insert(num.begin(), '1');
    }
    return num;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        cout << addOne(n) << endl;
    }
    return 0;
}