#include <bits/stdc++.h>

using namespace std;

int main() {
    long int n, d;
    cin >> n >> d;
    long int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);


    int count = 0;

    for (int i = 0; i < n - 1;) {
        if (arr[i] >= arr[i + 1] - d) {
            count++;
            i += 2;
        }
        else {
            i++;
        }

    }
    cout << count << endl;
    return 0;
}