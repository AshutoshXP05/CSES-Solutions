#include <bits/stdc++.h>
// with test cases
using namespace std;
void solve();
#define f(i, s, e) for (long long int i = s; i < e; i++) // FOR LOOP

#define MOD 1000000007 // MODULUS
#define PI 3.1415926535897932384626433832795
#define pb push_back // PUSH _ BACK
#define fi first     // FIRST
#define se second    // SECOND
#define endl '\n'    //  endl se fast hota hai isly we use /N
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

// Modular Arithmetic
ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }

ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }

ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

ll mod_inv(ll a) { return expo(a, MOD - 2); } // Using Fermat's Little Theorem

#define yes cout << "YES\n"; //  For yes
#define no cout << "NO\n";   // For No
typedef vector<int> vi;      // vector of int
typedef vector<vi> vvi;      // Vector of vector of int
typedef pair<int, int> ii;   // Pair of int int
typedef vector<ii> vii;      // Vector of pair of int int
typedef vector<ll> vll;      // Vector of long long
typedef double ld;           // For double
#define mii map<int, int>    // Map of int int
#define si set<int>          // Set of integer
#define sc set<char>         // Set of Character

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}

/*

int dp[501][125251] ;

int cntsum ( int n , int sum ) {
 
    if ( n == 0 ) return sum == n ;
    if ( sum == 0 ) return 1;

    if ( dp[n][sum] != -1 ) return dp[n][sum] % MOD;

    int nt = cntsum ( n - 1 , sum ) % MOD ;
    int t = 0 ;
    if ( sum - n >= 0 ) {
        t = cntsum ( n - 1 , sum - n ) % MOD ;
    }
    return dp[n][sum] = (nt + t) % MOD ;

}
*/

void solve() {
    int n;
    cin >> n;

    int sum = n * ( n + 1 ) / 2;

    if ( sum % 2 == 1 ) { cout << 0 << endl; return ;}
    int tar = sum / 2;

    // memset(dp, -1, sizeof(dp));
    // ll ans = cntsum(n, tar);
    // ans = ( ans %  MOD ) / 2;
    // ans = ( ans * mod_inv(2)) % MOD ;
    // cout << ans << endl;


/*

    vector<vector<int>> dp(n+1, vector<int>(tar+1, 0)) ;

    for ( int i=1; i<=n; i++ ) dp[i][0] = 1;
    dp[0][0] = 1;

    for ( int i=1; i<=n; i++ ) {
        for ( int j=0; j<=tar; j++  ) {

             int nt = dp[i - 1][j] % MOD ;
            int t = 0 ;
            if ( j - i >= 0 ) {
                t =  dp[i - 1][j - i ] % MOD ;
            }
             dp[i][j] = (nt + t) % MOD ;

        }
    }
    ll ans = (dp[n][tar] * mod_inv(2) ) %  MOD;
    cout << ans << endl;

*/


vector<int> prev(tar+1, 0);
vector<int> curr(tar+1, 0);

    prev[0] = 1;


for ( int i=1; i<=n; i++ ) {
    curr[0] = 1;
    for ( int j=0; j<=tar; j++ ) {

          int nt = prev[j] % MOD ;
            int t = 0 ;
            if ( j - i >= 0 ) {
                t =  prev[j - i ] % MOD ;
            }
             curr[j] = (nt + t) % MOD ;

    }
    prev = curr;
}
 ll ans = (prev[tar] * mod_inv(2) ) %  MOD;
    cout << ans << endl;
}
