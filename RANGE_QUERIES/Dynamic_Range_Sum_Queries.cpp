
// Application of Segment Tree --->

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

ll n;
vector<ll> arr;
vector<ll> segTree;

void buildTree(ll i, ll l, ll r)
{
    if (l == r)
    {
        segTree[i] = arr[l];
        return;
    }

    ll mid = l + (r - l) / 2;
    buildTree(2 * i + 1, l, mid);
    buildTree(2 * i + 2, mid + 1, r);

    segTree[i] = (ll)(segTree[2 * i + 1] + segTree[2 * i + 2]);
}

void updateTree(ll i, ll l, ll r, ll ind, ll val)
{
    if (l == r)
    {
        segTree[i] = val;
        return;
    }

    ll mid = l + (r - l) / 2;
    if (mid >= ind)
    {
        updateTree(2 * i + 1, l, mid, ind, val);
    }
    else
    {
        updateTree(2 * i + 2, mid + 1, r, ind, val);
    }
    segTree[i] = (ll)(segTree[2 * i + 1] + segTree[2 * i + 2]);
}

ll findSum(ll i, ll l, ll r, ll left, ll right)
{
    // case 1 : OverHead
    if (l > right || r < left)
        return 0;
    // case 2 : Inside the range
    if (l >= left && r <= right)
        return segTree[i];
    // case 3 : Overlapping range
    ll mid = l + (r - l) / 2;
    return findSum(2 * i + 1, l, mid, left, right) + findSum(2 * i + 2, mid + 1, r, left, right);
}

void solve()
{

    ll q;
    cin >> n >> q;

    arr.resize(n);
    segTree.resize(4*n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    buildTree(0, 0, n - 1);

    while (q--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            updateTree(0, 0, n - 1, b - 1, c);
        }
        else
        {
            ll sum = findSum(0, 0, n - 1, b - 1, c - 1) ;
            cout << sum << endl;
        }
    }
}