
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
//  vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    solve();
    // ans.clear();
    return 0;
}
/*
int dp[5001][5001] ;

int result(int i, int j, string &s, string &t) {
    if ( i == -1 ) return 1 + j ;
    if ( j == -1 ) return 1 + i;

    if ( dp[i][j] != -1 ) return dp[i][j] ;

    if ( s[i] == t[j] ) return dp[i][j] = 0 + result(i-1, j-1, s, t);
    else 
    return dp[i][j] =  min( { 1+ result(i-1, j, s, t), 1 + result(i, j-1, s, t), 1 + result(i-1, j-1, s, t)} );

}
*/
void solve() {
    string s, t;
    cin >> s >> t;
    // memset(dp, -1, sizeof(dp));
    // cout << result (s.length() - 1, t.length()-1, s, t);
    int n = s.length();
    int m = t.length();
/*
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

     for ( int i=1; i<=n; i++ ) {
        for ( int j=1; j<=m; j++ ) {
            dp[0][j] = j;
            dp[i][0] = i; 
        }
     }

    //  for ( int )
    for ( int i=1; i<=n; i++ ) {
        for ( int j=1; j<=m; j++ ) {
            if ( s[i-1] == t[j-1] ) dp[i][j] = dp[i-1][j-1] ;
            else {
                dp[i][j] = min ( { 1+dp[i-1][j] , 1+dp[i][j-1] , 1+dp[i-1][j-1]}) ;
            }
        }
    }
   cout << dp[n][m] << endl;

*/

    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);

    for ( int i=0; i<=m; i++ ) prev[i] =  i;
   

    for ( int i=1; i<=n; i++ ) {
        curr[0] =  1;
        for ( int j=1; j<=m; j++ ) {

            if ( s[i-1] == t[j-1] ) curr[j] = prev[j-1] ;
            else {
                curr[j] = min ( { 1+prev[j] , 1+curr[j-1] , 1+prev[j-1]}) ;
            }

        }
        prev = curr;
    }
    cout << prev[m] << endl;



}
