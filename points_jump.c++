#include <bits/stdc++.h>

using namespace std;
#include <iostream>


int d[55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    assert(T >= 1 && T <= 10000);
    
    while (T--) {
        int n;
        cin >> n;
        assert(n >= 1 && n <= 50);

        set<int> st;
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            assert(d[i] >= 1 && d[i] <= 100);
            st.insert(d[i]);
        }

        cout << st.size() << endl;
    }
    
    return 0;
}