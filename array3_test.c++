#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        long long proteinStored = 0;
        bool enoughProtein = true;
        int day = -1; 

        for (int i = 0; i < N; i++) {
            proteinStored += A[i];
            if (proteinStored < K) {
                enoughProtein = false;
                day = i + 1; 
                break;
            }
            proteinStored -= K;
        }

        if (enoughProtein) {
            cout << "YES" << endl;
        } else {
            cout << "NO " << day << endl;
        }
    }
    return 0;
}