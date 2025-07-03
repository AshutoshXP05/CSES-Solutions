
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


// vector<int> lcs ( int ind1, int ind2, vector<int> &a, vector<int> &b) {
     
//       if ( ind1 < 0 || ind2 < 0 ) return {};

//       if ( a[ind1] == b[ind2] ) {
        
//          vector<int> res = lcs(ind1 - 1, ind2 - 1, a, b );
//           res.pb(a[ind1]);
//           return res;
//       }
//       else{ 
//         // ans.pop_back();
//      vector<int> res1 = lcs(ind1 - 1, ind2, a, b );
//       vector<int> res2 = lcs(ind1, ind2 - 1, a, b  );

//       return ( res1.size() > res2.size() ) ? res1 : res2 ;
// }

// }


// vector<int> lcsSpaceOpt(vector<int> &a, vector<int> &b) {
//     int n = a.size(), m = b.size();
//     vector<vector<int>> prev(m+1), curr(m+1);

//     for (int i = 1; i <= n; i++) {
//         curr.assign(m+1, {});
//         for (int j = 1; j <= m; j++) {
//             if (a[i-1] == b[j-1]) {
//                 curr[j] = prev[j-1];
//                 curr[j].push_back(a[i-1]);
//             } else {
//                 curr[j] = (prev[j].size() > curr[j-1].size()) ? prev[j] : curr[j-1];
//             }
//         }
//         swap(prev, curr);
//     }

//     return prev[m];
// }


// vector<int> lcsTab(vector<int> &a, vector<int> &b) {
//     int n = a.size(), m = b.size();
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1));

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (a[i-1] == b[j-1]) {
//                 dp[i][j] = dp[i-1][j-1];
//                 dp[i][j].push_back(a[i-1]);
//             } else {
//                 dp[i][j] = (dp[i-1][j].size() > dp[i][j-1].size()) ? dp[i-1][j] : dp[i][j-1];
//             }
//         }
//     }

//     return dp[n][m];
// }


void print(vector<int> &ans ) {
    cout << ans.size() << endl;
     for ( auto it : ans ) {
        cout << it << " " ;
     }
     cout << endl;
}

vector<int> lcsMemo ( int i, int j, vector<int> &a, vector<int> &b) {
     if ( i == 0 || j == 0 ) return {};
     if ( a[i] == b[j] ) {
         vector<int> res = lcsMemo(i-1, j-1, a, b);
         res.pb(a[i]);
         return res;
     }
     vector<int> res1 = lcsMemo(i-1, j, a, b);
     vector<int> res2 = lcsMemo(i, j-1, a, b);

     return ( res1.size() > res2.size() ) ? res1 : res2 ;
}


void solve () {
     int n , m;
     cin >> n >> m ;
     vector<int> a(n);

     vector<int> b(m);
     for ( int i=0; i<n; i++ ) cin >> a[i] ;
     for ( int i=0; i<m; i++ ) cin >> b[i] ;

    //  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1));

    //  vector<int> ans =  lcsMemo( n-1, m-1 , a, b) ;

    vector<vector<int>> prev(m+1), curr(m+1);

    for ( int i=1; i<=n; i++ ) {
        for ( int j=1; j<=m; j++ ) {

             if ( a[i-1] == b[j-1] ) {
                 curr[j] = prev[j-1];
                 curr[j].pb(a[i-1]);
             }
             else {
                curr[j] = prev[j].size() > curr[j-1].size() ? prev[j] : curr[j-1] ;
             }
        }
        prev = curr;
    }

     print(prev[m]);
   
}

