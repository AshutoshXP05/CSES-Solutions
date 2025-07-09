
// Catalan Number --->

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void solve();
void precompute();
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
    precompute();
    solve();
    return 0;
}

     vector<ll> arr(1000001, 1);
     vector<ll> inverse(1000001, 1);

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

void precompute() {
    // precompute nCr ->
     for ( ll i=1; i<=1000000; i++ ) {
         arr[i] = ( arr[i-1] * i ) % MOD;
         inverse[i] = power(arr[i], MOD-2) % MOD;
     }
}

bool isValidSequence ( string str ) {
     int cnt = 0;
     for ( char ch : str ) {
        if ( ch == '(' ) cnt ++;
        else cnt--;
        if ( cnt == -1 ) return false;
     }
     return true;
}

void solve () {
    ll n;
    cin >> n;
    string str;
    cin >> str;

    if (n % 2 == 1) {
        cout << 0 << endl;
        return;
    }

    if ( ! isValidSequence( str )) {
        cout << 0 << endl;
        return;
    }

    int x = 0, y = 0;
    for (char ch : str) {
        if (ch == '(') x++;
        else y++;
    }

    n = n / 2;
    ll a = 2 * n - x - y;
    ll b = n - x;

    if (a < 0 || b < 0 || b > a) {
        cout << 0 << endl;
        return;
    }

    ll totalValidSequence = (arr[a] * inverse[b] % MOD * inverse[a - b] % MOD) % MOD;

    if (b - 1 < 0 || a < b - 1) {
        cout << totalValidSequence << endl;
        // cout << 0 << endl ;
        return;
    }

     ll totalInvalidSequence = (arr[a] * inverse[b - 1] % MOD * inverse[a - (b - 1)] % MOD ) % MOD;

    cout << ( (totalValidSequence - totalInvalidSequence + MOD ) % MOD ) << endl;
}
