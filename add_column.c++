#include <bits/stdc++.h>
using namespace std;

int main() {

    // n = number of elements
    // d = maximum allowed difference between two elements to form a pair
    long int n, d;
    cin >> n >> d;

    // Array to store the elements
    long int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array so that closest values stay together
    // This helps in pairing elements greedily
    sort(arr, arr + n);

    // Variable to count valid pairs
    int count = 0;

    // Traverse the sorted array
    // We compare current element with next element
    for (int i = 0; i < n - 1;) {

        // If difference between adjacent elements is <= d
        // then they can form a valid pair
        if (arr[i] >= arr[i + 1] - d) {

            // Increase pair count
            count++;

            // Move index by 2 since both elements are used
            i += 2;
        }
        else {

            // If they cannot form a pair,
            // move to next element and try again
            i++;
        }
    }

    // Print total number of valid pairs
    cout << count << endl;

    return 0;
}
