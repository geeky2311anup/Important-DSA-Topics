#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;      // 1 and numbers less than 1 are not prime
    if (n == 2) return true;       // 2 is the only even prime number
    if (n % 2 == 0) return false;  // all other even numbers are not prime

    // Check odd divisors from 3 up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        cout << (isPrime(N) ? "yes" : "no") << endl;
    }
    
    return 0;
}
