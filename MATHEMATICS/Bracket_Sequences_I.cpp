
// Catalan Number  --->

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void solve();
#define MOD 1000000007 // MODULUS
#define PI 3.1415926535897932384626433832795
#define pb push_back // PUSH _ BACK
#define fi first     // FIRST
#define se second    // SECOND
#define endl '\n'    //  endl se fast hota hai isly we use /N
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
#define yes cout << "YES\n"; //  For yes
#define no cout << "NO\n";   // For No

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}

// Mod Inverse 
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void solve () {
    
    ll n;
    cin >> n;
    if ( n % 2 == 1  ) { cout << 0 << endl; return ;}
    n = n / 2;
    vector<ll> dp(n, 0);
    dp[0] = 1;
    for ( int i=1; i<=n; i++ ) {
        ll res = 1;
        res = ( ( 4 * i - 2 ) * dp[i-1] * 1LL ) % MOD ; 
        res =  ( res * power ( i+1 , MOD-2 ) ) % MOD ;
        dp[i] = res;
    }

    cout << dp[n] << endl;

}