
//  Binary Search on Answer Problem --->

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

ll cntProducts ( ll mid, vector<int> &arr) {
    ll cnt = 0;
    for ( auto it : arr ) {
        cnt += (mid / it);
    }
    return cnt;
}

void solve()
{
    ll n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll low = *min_element(arr.begin(), arr.end());
    ll high = low * t;
    ll ans;
   while ( low <= high ) {
       ll mid = low + ( high - low ) / 2;
       if ( cntProducts(mid, arr) < t ) {
        low = mid + 1;
       }
       else {
          ans = mid ;
          high = mid - 1;
       }
   }
      cout << ans << endl;
}
