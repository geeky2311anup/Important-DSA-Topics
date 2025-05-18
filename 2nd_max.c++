#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int nums[3];
        for (int i = 0; i < 3; ++i) {
            cin >> nums[i];
        }
        sort(nums, nums + 3);
        cout << nums[1] << endl;
    }
    return 0;
}
