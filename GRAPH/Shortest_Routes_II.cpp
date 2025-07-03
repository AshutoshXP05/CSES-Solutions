#include <bits/stdc++.h>
//with test cases
using namespace std;
void solve();
#define f(i,s,e) for(long long int i=s;i<e;i++)      // FOR LOOP 

#define MOD 1000000007         // MODULUS 
#define PI 3.1415926535897932384626433832795
#define pb push_back       // PUSH _ BACK 
#define fi first         // FIRST 
#define se second    //SECOND 
#define endl '\n'      //  endl se fast hota hai isly we use /N 
typedef long long ll;

ll expo(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % MOD; a = (a * a) % MOD; b = b >> 1;} return res;} 


// Modular Arithmetic
ll mod_add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }

ll mod_sub(ll a, ll b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }

ll mod_mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

ll mod_inv(ll a) { return expo(a, MOD - 2); }  // Using Fermat's Little Theorem

#define yes cout<<"YES\n";              //  For yes 
#define no cout<<"NO\n";               // For No
typedef vector<int> vi;                // vector of int 
typedef vector<vi> vvi;                 // Vector of vector of int 
typedef pair<int, int> ii;      // Pair of int int 
typedef vector<ii> vii;        // Vector of pair of int int 
typedef vector<ll> vll;     // Vector of long long 
typedef double ld;         // For double
#define mii map<int, int>  // Map of int int 
#define si set<int>      // Set of integer 
#define sc set<char>    // Set of Character 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}

void solve(){
    ll n,m,q;
    cin >> n >> m >> q;
    
    vector<vector<ll>> adj(n+1, vector<ll>(n+1, LLONG_MAX));
    ll u,v,w;
    for ( int i=1; i<=m; i++ ) {
        cin >> u >> v >> w;
        if ( adj[u][v] > w)
       { adj[u][v] = w;
        adj[v][u] = w;}
    }
    
    for ( int i=1; i<=n; i++ ) adj[i][i] = 0;

    for ( int via=1; via<=n; via++ ) {
        for ( int i=1; i<=n; i++ ) {
            for ( int j=1; j<=n; j++ ) {
                 if ( adj[i][via] != LLONG_MAX && adj[via][j] != LLONG_MAX ) 
                 adj[i][j] = min(adj[i][j], (adj[i][via] + adj[via][j]));
            }
        }
    }

    ll x,y;
    for ( int i=0; i<q; i++ ) {
        cin >> x >> y ;
        if ( adj[x][y] == LLONG_MAX ) cout << -1 << endl;
        else cout << adj[x][y] << endl;
    }
    return ;
}