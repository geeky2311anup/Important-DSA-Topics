#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    assert(1 <= t && t <= 200);
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        assert(n == s.size());
        assert(1 <= s.size() && s.size() <= 1000);
        for (auto c: s) assert('a' <= c && c <= 'z');
        int mask = 0;
        for (auto c: s) mask ^= 1 << (c - 'a');
        cout << (mask ? "NO\n" : "YES\n");
    }
    
    return 0;
}

