#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the largest common element between two arrays
int largestCommonElement(vector<int>& arr1, vector<int>& arr2) {
    
    // Sort both arrays in ascending order
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // Start from the last index (largest elements)
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;

    // Traverse both arrays from the end
    while (i >= 0 && j >= 0) {
        
        // If elements are equal, we found the largest common element
        if (arr1[i] == arr2[j]) {
            return arr1[i];
        }
        // If arr1's element is greater, move i backward
        else if (arr1[i] > arr2[j]) {
            i--;
        }
        // If arr2's element is greater, move j backward
        else {
            j--;
        }
    }

    // If no common element is found, return -1
    return -1;
}

int main() {
    int n, m;

    // Read sizes of the two arrays
    cin >> n >> m;

    // Create first array of size n
    vector<int> arr1(n);

    // Input elements of first array
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    // Create second array of size m
    vector<int> arr2(m);

    // Input elements of second array
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    // Print the largest common element
    cout << largestCommonElement(arr1, arr2) << endl;

    return 0;
}
