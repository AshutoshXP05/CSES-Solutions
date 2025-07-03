
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
int dp[1000001] ;



int cntNo ( int n ) {
    // cout << n << " " ;
    if ( n == 0 ) return 1;

    if ( dp[n] != -1 ) return dp[n];

    int maxi = INT_MAX;
    for ( int i=0; i < (to_string(n)).length(); i++  ) {
        string str = to_string(n);
        if ( str[i] == '0' ) continue;
        int cnt = 0;
       cnt = 1 + cntNo( n - (str[i] - '0' ) ) ;
       maxi = min(maxi, cnt );
    }
    return dp[n] = maxi;
}

*/

void solve () {
    int n;
    cin >> n;
    // memset(dp, -1, sizeof(dp));
    // cout << cntNo ( n )  - 1 ;

    /*
    vector<int> dp(n+1, INT_MAX);

    dp[0] = 0;

   

    for ( int i=1; i<=n; i++ ) {
        string str = to_string(i);
 
         for ( int j=0; j < str.length(); j++  ) {
        if ( str[j] == '0' ) continue;

       dp[i] = min(dp[i], 1 + dp[i - (str[j] - '0')] ) ;

    }

    }
 cout << dp[n] ;

 */

 vector<int> dp(10, 1);

 dp[0] = 0;

 for ( int i=10; i<=n; i++ ) {

     string str = to_string(i);
 
     int newval = INT_MAX ;
         for ( int j=0; j < str.length(); j++  ) {
        if ( str[j] == '0' ) continue;

        newval = min(newval,  1 + dp[10 - (str[j] - '0')] ) ;
    
 }

   dp.erase(dp.begin());
   dp.pb(newval);

}

cout << dp[9];

}

