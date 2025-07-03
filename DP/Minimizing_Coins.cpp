#include <bits/stdc++.h>
using namespace std;
void solve();
#define f(i, s, e) for (long long ll i = s; i < e; i++)
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define fi first
#define se second
#define endl '\n'
typedef long long ll;

ll expo(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b = b >> 1;
    }
    return res;
}

ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll mod_inv(ll a) { return expo(a, MOD - 2); }

#define yes cout << "YES\n";
#define no cout << "NO\n";
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef double ld;
#define mii map<ll, ll>
#define si set<ll>
#define sc set<char>
int ind = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    // long long t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // ind = -1;
    // }
    return 0;
}

// int dp[1000001][101] ;


// int cntcoin(int x, int ind, vector<int> &a) {
  
//     if ( ind == 0 ) {
//         return ( x % a[ind] == 0 ) ?  x / a[ind]  : INT_MAX ;
//     }


//     int nt = cntcoin(x, ind-1, a );
//     int t = INT_MAX;
//     if ( x - a[ind] >= 0 ) {
//         t = 1 + cntcoin(x-a[ind], ind, a);
//     }

//     return dp[x][ind] = min(nt, t);

// }


void solve () {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for ( int i=0; i<n; i++) cin >> a[i];

    // memset(dp, -1, sizeof(dp));

    // cout << cntcoin(x, n-1, a);


    vector<vector<int>> dp(n, vector<int>(x+1, -1));

    vector<int> prev(x+1, 0), curr(x+1, 0);
    // if ( x % a[0] == 0 ) p

    // if ( x % a[0] == 0 ) dp[0][x%a[0]] = x / a[0];
    // else dp[0][x%a[0]] 

    // for ( int i=0; i<=x; i++ ) {
    //     if ( i % a[0] == 0 ) dp[0][i] = i / a[0];
    //     else dp[0][i] = 1e9;
    // }
    for ( int i=0; i<=x; i++ ) {
        if ( i % a[0] == 0 ) prev[i] = i / a[0];
        else prev[i] = 1e9;
    }

    // for ( int i=1; i<n; i++ ) {
    //     for ( int j=0; j<=x; j++ ) {
    //         int t = 1e9;
    //         if ( j - a[i] >= 0 ) {
    //             t = 1 + dp[i][j-a[i]] ;
    //         }
    //         int nt = dp[i-1][j];
    //         dp[i][j] = min(nt, t);
    //     }
    // }
    for ( int i=1; i<n; i++ ) {
        for ( int j=0; j<=x; j++ ) {
            int t = 1e9;
            if ( j - a[i] >= 0 ) {
                t = 1 + curr[j-a[i]] ;
            }
            int nt = prev[j];
            curr[j] = min(nt, t);
        }
        prev = curr;
    }

    if ( prev[x] == 1e9 ) cout << -1 << endl;
    else 
    cout << prev[x] << endl;

}