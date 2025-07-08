
//  Sliding Window Xor --->

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
    ll n, k, a, b, c, x;
    cin >> n >> k >> x >> a >> b >> c ;
   
    int ans = 0;
    for ( ll i=0; i<n; i++ ) {
        int ind = min({i+1, n-i, k});
        if ( ind % 2 != 0 ) {
            ans ^= x ;
        }
        x = ( x * a + b ) % c;
    }

    cout << ans << endl;

}

