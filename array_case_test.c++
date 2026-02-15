#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>


#define ll long long
#define vll vector<ll>

const ll INF = 1e18;
const int N = 1e5 + 11, mod = 1e9 + 7;

void solve() {
    int n, id1 = -1, idn = -1;
    cin >> n;
    vll p(n);
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == 1) id1 = i;
        if (p[i] == n) idn = i;
    }
    
    cout << id1 + n - 1 - idn - (id1 > idn) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test;
    cin >> test;
    while (test--) solve();
    
    return 0;
}