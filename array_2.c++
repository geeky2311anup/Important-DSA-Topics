#include <iostream>
#include <vector>
using namespace std;

void retrieveArray(int N, vector<long long>& B) {
   
    long long sumB = 0;
    for (int i = 0; i < N; i++) {
        sumB += B[i];
    }
    long long S = sumB / (N + 1);

  
    for (int i = 0; i < N; i++) {
        cout << (B[i] - S) << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> B(N);
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        retrieveArray(N, B);
    }
    return 0;
}
