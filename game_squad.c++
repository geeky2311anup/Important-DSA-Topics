#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <iostream>

int A [156];
int B [156];
int C [156];
int main()
{

    //For the test case.
    int tc;
    cin>>tc;
    while(tc--){

    int n,c;

    // Length of the array
    cin>>n;
    assert(n>0 && n<=150);
    for(int i=0; i<n ; i++)
    {
        cin>>A[i];
        assert( A[i]>=0 && A[i]<=50 );
    }
    for(int i=0 ; i<n ; i++)
    {
        cin>>B[i];
        assert( B[i]>=0 && B[i]<=50 );

    }
      //Calculating the value of each players point
    for(int i=0 ; i<n ;  i++)
    {
        C[i]=(A[i]*20)-(B[i]*10);
    }

    int Mx= -1000;
    //Finding out the maximum point.
    for(int i=0; i<n ; i++)
    {
        Mx= max(Mx,C[i]);
    }

    if( Mx<=0 ) cout<<0<<endl;
    else cout<<Mx<<endl;

    }




}