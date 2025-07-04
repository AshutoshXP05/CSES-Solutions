
//  Application of Segment Tree --->

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

void buildTree(int i, int l, int r)
{
    if (l == r)
    {
        segTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildTree(2 * i + 1, l, mid);
    buildTree(2 * i + 2, mid+1, r);

    segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
}

int minQuery(int i, int l, int r, int left, int right)
{
    if (l > right || r < left)
        return INT_MAX;

    if (l >= left && r <= right)
        return segTree[i];

    int mid = l + (r - l) / 2;
    return min(minQuery(2 * i + 1, l, mid, left, right), minQuery(2 * i + 2, mid + 1, r, left, right));
}

void solve()
{

    ll q;
    cin >> n >> q;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    segTree.resize(4 * n);

    buildTree(0, 0, n - 1);

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << minQuery(0, 0, n - 1, a - 1, b - 1) << endl;
    }
}