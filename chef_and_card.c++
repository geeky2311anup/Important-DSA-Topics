#include <iostream>
using namespace std;

// Function to calculate digit sum of a number
int digitSum(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int chefPoints = 0, mortyPoints = 0;

        for (int i = 0; i < N; i++) {
            long long A, B;
            cin >> A >> B;

            int powerA = digitSum(A);
            int powerB = digitSum(B);

            if (powerA > powerB) {
                chefPoints++;
            } else if (powerB > powerA) {
                mortyPoints++;
            } else {
                chefPoints++;
                mortyPoints++;
            }
        }

        if (chefPoints > mortyPoints) {
            cout << 0 << " " << chefPoints << "\n";
        } else if (mortyPoints > chefPoints) {
            cout << 1 << " " << mortyPoints << "\n";
        } else {
            cout << 2 << " " << chefPoints << "\n"; // same as mortyPoints
        }
    }

    return 0;
}
