
//  Implementation of Begger's Formula --->

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

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    ll res = 1;
    for (ll i = 1; i <= r; i++) {
        res = res * (n - i + 1) % MOD;
        res = res * power(i, MOD - 2) % MOD; // modular inverse
    }
    return res;
}

void solve () {
    ll n, m ;
    cin >> n >> m;

    cout << nCr ( m+n-1,  n-1) << endl;

}