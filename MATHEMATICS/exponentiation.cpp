#include<bits/stdc++.h>
using namespace std;

long long power (int a, int b) {
    if ( b == 0 ) return 1;
    long long half = power(a,b/2);
    half = ( half * half )% 1000000007;
    if ( b % 2 == 0) return half;
    else return (half * a % 1000000007) % 1000000007;

}

int main () {
    int t;
    cin >> t;
    while ( t-- ) {
        int a,b;
        cin >> a >> b;
        
       long long res = power ( a, b);
       cout << res << endl;
    }
}