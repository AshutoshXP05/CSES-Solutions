
// Basic Binomial Concept --->

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

// ll fact(ll n) {

//     ll factorial = 1;
//     for ( int i = 1; i<=n; i++ ) {
//         factorial =  ( factorial * i * 1LL ) % MOD ;
//     }
//     return factorial;
// }

void solve () {
     ll n;
     cin >> n ;

     vector<ll> arr(1000001, 1);
     vector<ll> inverse(1000001, 1);

     for ( ll i=1; i<=1000000; i++ ) {
         arr[i] = ( arr[i-1] * i ) % MOD;
         inverse[i] = power(arr[i], MOD-2) % MOD;
     }
     

     while ( n-- ) {
        ll b, a;
        cin >> a >> b;

        ll result =  1;
        // result = ( result * fact(a) * 1LL ) % MOD;
        // result = ( result * power( fact(b), MOD-2) * 1LL ) % MOD;
        // result = ( result * power ( fact(a-b), MOD-2) * 1LL ) % MOD;

        b = min ( b , a-b ) ;
        result = ( result * arr[a] * 1LL ) % MOD ;
        result = ( result * inverse[b] * 1LL ) % MOD ;
        result = ( result * inverse[a-b] * 1LL ) % MOD ;

        cout << result << endl;
     }
}