
//  Modulus Operation and Hash Map --->

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
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<ll, int> mpp;
    ll sum = 0;
    ll cnt = 0;
    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        ll rem = sum % n;
        if (rem < 0)
        {
            cnt += mpp[rem + n];
            mpp[rem + n]++;
        }
        else
        {
            cnt += mpp[rem];
            mpp[rem]++;
        }
    }
    cout << cnt << endl;
}
