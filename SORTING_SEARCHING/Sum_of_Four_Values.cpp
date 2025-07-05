
//  3 SUM Problem --->

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    // long long t;          // Test cases wala ..
    // cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}

void solve () {
    ll n, x; 
    cin >> n >> x;
    vector<pair<ll,ll>> arr(n+1);
    for ( ll i=1; i<=n; i++ ) {
        ll x;
        cin >> x;
        arr[i] = {x, i};
    }

    sort(arr.begin(), arr.end());

    int i, j , k, l;
    bool found = false;

    for (  i=1; i<=n; i++ ) {
        for ( j=i+1; j<=n; j++ ) {

            if ( j - i != 1 && arr[j] == arr[j-1] ) { continue;}

             k = j+1;
             l = n;

             while ( k < l ) {
                 if ( k != l && k - j != 1 && arr[k].fi == arr[k-1].fi  ) { k++; continue;}
                 if ( l != k && l + 1 <= n && arr[l].fi == arr[l+1].fi ) { l--; continue; }

                 ll sum = arr[i].fi + arr[j].fi + arr[k].fi + arr[l].fi;
                 if ( sum == x ) {
                    cout << arr[i].se << " " << arr[j].se << " " << arr[k].se << " " << arr[l].se << endl;
                    return;
                 }
                 else if ( sum < x ) k++;
                 else l--;
             }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}