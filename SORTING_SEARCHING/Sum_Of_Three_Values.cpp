
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
    vector<int> arr(n+1);
    for ( int i=1; i<=n; i++ ) cin >> arr[i];

    unordered_multimap<int,int> mpp;
    for ( int i = 1; i<=n; i++ ) {
        mpp.insert({arr[i], i});
    }

    sort(arr.begin(), arr.end());

    int i, j , k;
    bool found = false;

    for (  i=1; i<=n; i++ ) {
         j = i+1;
         k = n ;
        while ( j < k ) {
            if ( j - i != 1 && arr[j] == arr[j-1]  ) { j++; continue; }
            if ( k + 1 <= n && arr[k] == arr[k+1]  ) { k--; continue; }
            ll sum = arr[i] + arr[j] + arr[k] ;
            if ( sum == x ) {
                found = true;
                // cout << i << " " << j << " " << k << endl;
                break;
            } 
         
            if ( sum < x ) j++;
            else k--;
        } 
          if ( found ) break;
    }
   
    // cout << i << " " << j << " " << k << endl;

    if ( found ) {
        vector<int> ans;
        auto it1  = mpp.find(arr[i]);
        ans.pb(it1 -> se);
        mpp.erase(it1);

        auto it2  = mpp.find(arr[j]);
        ans.pb(it2 -> se);
        mpp.erase(it2);

        auto it3  = mpp.find(arr[k]);
        ans.pb(it3 -> se);
        mpp.erase(it3);

        sort(ans.begin(), ans.end());

        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }

   else  cout << "IMPOSSIBLE" << endl;
}