
//  Sliding Window and Multiset --->

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
    solve();
    return 0;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

        multiset<ll> st(arr.begin(), arr.begin()+k);
        auto it = st.begin();
        advance(it, k/2);

        int i = 0;
        int j = k;

        while ( true ) {
           
            if ( k % 2 == 0  ) {
                cout << *prev(it) << " ";
            }
            else {
                 cout << *(it) << " ";
            }
            // check boundness
            if ( j == n ) return;
            // insertion 
            st.insert(arr[j]);
            // maintain it
            if ( arr[j] < *(it) ) it--;

            // deletion
            if ( arr[i] <= *(it) ) it++;

            // remove from set
            st.erase(st.lower_bound(arr[i]));

            i++;
            j++;
        }
          return;
}