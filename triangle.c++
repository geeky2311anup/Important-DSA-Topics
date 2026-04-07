#include<bits/stdc++.h>
using namespace std;

// Type aliases for convenience
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

// Constants
#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()

int main(){
    // Fast I/O (important for competitive programming)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; 
    cin >> T;  // Number of test cases

    while(T--){
        int D, L, R;
        cin >> D >> L >> R;
        // D = current day
        // L = earliest day to take second dose
        // R = latest day to take second dose

        // If current day is before allowed window
        if(D < L) 
            cout << "Too Early\n";

        // If current day is within allowed window
        else if(L <= D && D <= R) 
            cout << "Take second dose now\n";

        // If current day is after allowed window
        else 
            cout << "Too Late\n";
    }

    return 0; // Program ends successfully
}
