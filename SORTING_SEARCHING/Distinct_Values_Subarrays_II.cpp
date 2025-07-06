
//  Sliding Window and Hash Map --->

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



void solve() {
    ll n , x;
    cin >> n >> x;
    vector<ll> arr(n);
    for ( int i=0; i<n; i++ ) cin >> arr[i];

    unordered_map<ll, int> mpp;
    ll left = 0, ans = 0;

    for ( ll right = 0; right < n; right ++ ) {
        mpp[arr[right]]++;

        while ( mpp.size() > x ) {
            mpp[arr[left]]--;
            if ( mpp[arr[left]] == 0 ) {
                mpp.erase(arr[left]);
               
            } 
            left++;
        }
        ans += ( right - left  +1);
    }

    cout << ans << endl;
    
}

