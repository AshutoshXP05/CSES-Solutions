
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
int dp[1001][1000001];

int ans ( int ind, int x, vector<int> &pages, vector<int> &prices) {
     if ( ind == 0 ) {
        if ( prices[ind] <= x ) return pages[ind];
        else return 0;
     }

     int ntake = ans(ind-1, x, pages, prices);

     int take = 0;
     if ( prices[ind] <= x  ) take =  pages[ind] + ans(ind-1, x-prices[ind], pages, prices) ;
     
     return max(take, ntake ) ;
}
*/

void solve() {
    int n,x;
    cin >> n >> x;
    vector<int> pages(n), prices(n);
    for ( int i=0; i<n; i++ ) cin >> prices[i];
    for ( int i=0; i<n; i++ ) cin >> pages[i];

    // cout << ans(n-1, x, pages, prices );

/*
    vector<vector<int>> dp(n, vector<int>(x+1, 0));

    for ( int i=0; i<=x; i++ ) {
        if ( i >= prices[0]  ) dp[0][i] = pages[0];
    }

    for ( int i=1; i<n; i++ ) {
        for ( int j = 0; j<=x; j++ ) {

            int ntake = dp[i-1][j];

            int take = 0;
            if ( prices[i] <= j  ) take =  pages[i] + dp[i-1][j-prices[i]] ;
            
            dp[i][j] = max(take, ntake ) ;

        }
    }
        cout << dp[n-1][x]; 

*/

    vector<int> prev(x+1, 0);
    vector<int> curr(x+1, 0);

      for ( int i=0; i<=x; i++ ) {
        if ( i >= prices[0]  ) prev[i] = pages[0];
    }


        for ( int i=1; i<n; i++ ) {
                for ( int j = 0; j<=x; j++ ) {

                    int ntake = prev[j];

                    int take = 0;
                    if ( prices[i] <= j  ) take =  pages[i] + prev[j-prices[i]] ;
                    
                    curr[j] = max(take, ntake ) ;

                }
                prev = curr;
            }
                cout << prev[x]; 

}


