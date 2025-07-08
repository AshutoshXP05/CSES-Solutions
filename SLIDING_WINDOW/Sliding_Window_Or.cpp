
//  Using prefix and Suffix Or --->

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
   
    vector<ll> arr(n);
    for ( int i=0; i<n; i++ )  {
        arr[i] = x;
        x = ( x * a + b ) % c;
    }

    vector<ll> pre(n), suff(n);
    pre[0] = arr[0];
    suff[n-1] = arr[n-1];

    for ( int i=1; i<n; i++ ) {
        if ( i % k == 0 ) {
            pre[i] = arr[i] ;
        }
        else 
        pre[i] = pre[i-1] | arr[i] ;
    }

    for ( int i=n-2; i>=0; i-- ) {
        if ( i % k == k-1 ) {
            suff[i] = arr[i];
        }
        else 
        suff[i] = arr[i] | suff[i+1];
    }

     ll ans = 0;
     ll low = 0, high = k-1;

     while ( high < n ) {
        if( high % k == k-1 )
        ans ^= pre[high];

        else {
            ans ^= pre[high] | suff[low];
        }

        low++;
        high++;
     }

     cout << ans << endl;

}

