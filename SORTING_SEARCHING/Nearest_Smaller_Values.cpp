
//  Min Stack Concept --->

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
    vector<pair<ll, ll>> arr(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        arr[i] = {x, i};
    }

    stack<pair<int, int>> st;

    for (int i = 1; i <= n; i++)
    {

        while (!st.empty())
        {

            if (st.top().fi < arr[i].fi)
            {
                //    ans[i] = st.top().se;
                cout << st.top().se << " ";
                break;
            }

            else
            {
                while (!st.empty() && st.top().fi >= arr[i].fi)
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    cout << st.top().se << " ";
                }
                break;
            }
        }
        if (st.empty())
            cout << 0 << " ";

        st.push({arr[i].fi, arr[i].se});
    }
}