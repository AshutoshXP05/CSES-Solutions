
//  Sliding Window and Binary Search  --->

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

bool canPossibleDivision(ll mid, vector<ll> &arr, ll k)
{
    ll n = arr.size();
    ll sum = 0;
    ll partition = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            partition++;
        }
    }
    return partition <= k;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll low = *max_element(arr.begin(), arr.end());
   
    ll high = accumulate(arr.begin(), arr.end(), 0LL);
    //  if (k == 1)
    // {
    //     cout << low << endl;
    //     return;
    // }
    ll ans = 0;

    while (low <= high)
    {

        ll mid = low + (high - low) / 2;

        if (canPossibleDivision(mid, arr, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;
}
