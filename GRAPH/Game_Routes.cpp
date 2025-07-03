#include <bits/stdc++.h>
//with test cases
using namespace std;

#define f(i,s,e) for(long long ll i=s;i<e;i++)      // FOR LOOP 

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
typedef vector<ll> vi;                // vector of ll 
typedef vector<vi> vvi;                 // Vector of vector of ll 
typedef pair<ll, ll> ii;      // Pair of ll ll 
typedef vector<ii> vii;        // Vector of pair of ll ll 
typedef vector<ll> vll;     // Vector of long long 
typedef double ld;         // For double
#define mii map<ll, ll>  // Map of ll ll 
#define si set<ll>      // Set of integer 
#define sc set<char>    // Set of Character 
void solve();


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}



void solve(){
     ll n, m;
     cin >> n >> m;
     vector<vector<ll>> adj(n+1);
     vector<int> indegree(n+1, 0);
     for ( ll i=0; i<m; i++ ) {
        ll u,v;
        cin >> u >> v;
        adj[u].pb(v);
        indegree[v]++; 
     }

     queue<int> q;
     vector<int> ways(n+1, 0);
     for ( int i=1; i<=n; i++ ) {
        if ( indegree[i] == 0 ) q.push(i);
     }
    ways[1] = 1;
     while ( !q.empty() ) {
          int node = q.front();
          q.pop();
          for ( auto it : adj[node] ) {
            ways[it] = (ways[it] + ways[node]) % MOD;
             indegree[it] --;
             if ( indegree[it] == 0 ) q.push(it);
          }
     }
    //    if ( indegree[n] == 0 )  cout << 0;
       cout << ways[n];
}



