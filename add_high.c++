#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
#include <iostream>


int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> Arr(N); 
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans ^= Arr[i];
        }
        cout << ans << endl;
    }
}
