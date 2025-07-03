#include <bits/stdc++.h>
//with test cases
using namespace std;

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

void solve();

class Disjoint {

    public:

    vector<ll> parent, size;

    Disjoint (ll n) {
        parent.resize(n+1);
        size.resize(n+1);
        for ( ll i=1; i<=n; i++ ) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    ll findpar ( ll u) {
        if ( parent[u] == u ) return u;
        return parent[u] = findpar(parent[u]);
    }

    void unionBySize (ll u, ll v) {
        int Upar = findpar(u);
        int Vpar = findpar(v);
        if ( Upar == Vpar ) return;

        if ( size[Upar] < size[Vpar] ) {
            size[Vpar] += size[Upar];
            parent[Upar] = parent[Vpar];
        }
        else {
            size[Upar] += size[Vpar];
            parent[Vpar] = parent[Upar];
        }
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}

void solve(){
     ll n,m;
     cin >> n >> m;
    //  vector< pair<ll,ll>> adj(n);
    vector<pair<ll, pair<ll, ll>>> adj;
    Disjoint ds(n);
     ll u,v,w;
     for ( ll i=1; i<=m; i++ ) {
         cin >> u >> v >> w;
         adj.push_back({w,{u,v}});
       
     }
     
     sort(adj.begin(), adj.end() ) ;
      ll cnt = 0;
      ll maxDis = 0;
     for ( auto it : adj ) {
         ll wt = it.first;
         ll u = it.second.first;
         ll v = it.second.second;

         ll ulp_u = ds.findpar(u);
         ll ulp_v = ds.findpar(v);
         if ( ds.findpar(ulp_u) != ds.findpar(ulp_v) ) {
              maxDis += wt;
              cnt ++;
              ds.unionBySize (ulp_u, ulp_v);
         }
     }

     if ( cnt != n-1 ) { 
        cout << "IMPOSSIBLE";
        return;
     }
     
    //  for ( auto it : ds.size ) cout << it << " " ;
    //  cout << endl;
    //  for ( auto it : ds.parent ) cout << it << " " ;
    //  cout << endl;

     cout << maxDis << endl;
}

// 10 10
// 7 9 3
// 6 10 4
// 3 5 7
// 8 10 6
// 3 7 3
// 5 9 2
// 2 4 4
// 1 3 5
// 4 6 9
// 2 6 2