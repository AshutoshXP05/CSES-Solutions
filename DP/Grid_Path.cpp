
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

// int cnt( int r, int c, )

bool valid ( int r, int c, int  n,  vector<vector<char>> &mat) {
    return r >=0 && c >= 0 && r < n && c < n && mat[r][c] != '*' ;
}


void solve () {

    int n; 
    cin >> n;

    vector<vector<char>> mat(n, vector<char>(n));

    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) cin >> mat[i][j];
    }

    if ( mat[0][0] == '*' || mat[n-1][n-1] == '*') { cout << 0 << endl; return; }

    vector<int> prev(n, 0);
    
     prev[0] = 1;

     for ( int i=0; i<n; i++ ) {
        vector<int> curr(n, 0);
        for ( int j=0; j<n; j++ ) {
            if ( i == 0 && j == 0 ) {curr[0] = 1;  continue;}
            int left = 0, up = 0;
             if ( valid(i, j-1, n, mat)  ) {
                 left = curr[j-1] % MOD;
             }
             if ( valid ( i-1, j, n, mat ) ) {
                 up = prev[j] % MOD ;
             }
             curr[j] = (left + up) % MOD ;
        }
        prev = curr;
     }
     cout << prev[n-1];
}





