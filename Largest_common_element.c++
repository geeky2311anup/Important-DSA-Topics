#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestCommonElement(vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = arr1.size() - 1;
    int j = arr2.size() - 1;

    while (i >= 0 && j >= 0) {
        if (arr1[i] == arr2[j]) {
            return arr1[i];
        } else if (arr1[i] > arr2[j]) {
            i--;
        } else {
            j--;
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    vector<int> arr2(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    cout << largestCommonElement(arr1, arr2) << endl;

    return 0;
}