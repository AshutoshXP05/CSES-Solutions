
// Dearrangement Problem  --->

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

void solve () {
   
    ll n ;
    cin >> n ;

    ll dp[n+1];
    dp[1] = 0, dp[2] = 1;
    for ( int i=3; i<=n; i++ ) {
        dp[i] =  ( ((dp[i-1] + dp[i-2]) % MOD) * (i-1) * 1LL ) % MOD ;
    }

    cout << dp[n] << endl;

}