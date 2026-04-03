#include<bits/stdc++.h>
using namespace std;

// Function to solve one test case
void solve()
{
    int a[3];

    // Input three integers
    cin >> a[0] >> a[1] >> a[2];

    // Sort the array in ascending order
    sort(a, a + 3);

    // After sorting:
    // a[0] -> smallest
    // a[1] -> middle
    // a[2] -> largest

    // Print the sum of the two largest numbers
    cout << (a[2] + a[1]) << "\n";
}

int main()
{
    // Uncomment below lines if using file input/output
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;

    // Number of test cases
    cin >> t;

    // Run solve() for each test case
    while(t--)
        solve();

    return 0;
}
