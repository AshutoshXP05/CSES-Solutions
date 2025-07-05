
//  2-Pointer Technique --->

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
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    ll sum = arr[1];
    int i = 1;
    int j = 1;
    ll cnt = 0;

    while (sum < x && j + 1 <= n)
    {
        j++;
        sum += arr[j];
    }
    if (sum == x)
    {
        cnt++;
    }
    sum -= arr[i];
    i++;
}

cout << cnt << endl;
}
