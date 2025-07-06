
//  Simple sorting of array --->

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

void solve()
{
    ll n;
    cin >> n;
    vector<int> arrival(n);
    vector<int> departure(n);
    for (int i = 0; i < n; i++) {
        cin >> arrival[i] >> departure[i];
    }

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

  int i = 0, j = 0;
    ll cnt = 0;
    ll ans = 0;

    while (i < n) {
        if (arrival[i] < departure[j]) {
            cnt++;               // a new guest arrives
            cout << cnt << " ";  // print current active rooms
            ans = max(ans, cnt); // update max if needed
            i++;
        } else {
            cnt--; // a guest leaves
            j++;
        }
    }
    cout << endl;
}
