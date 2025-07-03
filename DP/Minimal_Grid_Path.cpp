
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

int dp[3001][3001] ;

bool isValid( int r, int c, int n ) {
    return r >= 0 && c >= 0 && r < n && c < n ;
}

/*
string minPath( int r, int c, int n, vector<vector<char>> &v,  vector<vector<string>> &dp) {
    if ( r == n-1 && c == n-1 ) return string(1, v[r][c]) ;
    if (  dp[r][c] != "" ) return dp[r][c] ;
    string right = {'~'};
    string down = {'~' }; 
    if ( isValid(r, c+1, n) ) {
        right =  minPath(r, c+1,n , v, dp); 
    }
    if ( isValid(r+1, c, n) ) {
         down =  minPath (r+1, c, n, v, dp) ;
    }
   string best = (right < down) ? right : down;
    return dp[r][c] = v[r][c] + best ;

}
*/

void solve() {
    int n; 
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) cin >> v[i][j] ;
    }
    // vector<vector<string>> dp(n+1, vector<string>(n+1, ""));
    // string res = minPath(0, 0, n, v, dp) ;

//    cout << res << endl;

/*
    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) {

            if ( i == 0 && j  == 0 ) {dp[0][0] = string(1, v[0][0]); continue;}

            string right = {'~'};
            string down = {'~' }; 
            if ( isValid(i, j-1, n) ) {
                right =  dp[i][j-1]; 
            }
            if ( isValid(i-1, j, n) ) {
                down = dp[i-1][j];
            }
        string best = (right < down) ? right : down;
             dp[i][j] = best + v[i][j] ;

        }
    }
         cout << dp[n-1][n-1] << endl;
*/

    
vector<vector<char>> prev(n + 1), curr(n + 1);

        for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) {

            if ( i == 0 && j  == 0 ) {curr[0].pb(v[0][0]); continue;}

            vector<char> right = {'~'};
             vector<char> down = {'~' }; 
            if ( isValid(i, j-1, n) ) {
                right =  curr[j-1]; 
            }
            if ( isValid(i-1, j, n) ) {
                down = prev[j];
            }
        vector<char> best = (right < down) ? right : down;
             curr[j] = best ;
            curr[j].pb( v[i][j]) ;

        }
        prev = curr;
    }
         
    for ( char ch : prev[n-1] ) {
        cout << ch << "";

    }
    cout << endl;


}



