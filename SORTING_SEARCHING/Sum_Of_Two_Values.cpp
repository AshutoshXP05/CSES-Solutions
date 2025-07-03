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
    long long n,tar,i,l=-1,m=-1,j=0,k=0,count=0,ans;
    cin>>n>>tar;
    vector<long long> a(n);
    map<ll,ll> mpp;
    f(i,0,n){
        cin>>a[i]; 
    }
    // ll tar ;
    ll maxi = INT_MIN;

    for  ( ll i=0; i<n; i++ ) {
        if ( mpp.find(tar - a[i]) != mpp.end() ) {
            j = mpp[tar-a[i]];
            k=i;
            if ( (abs(j-k)) >= maxi ) {
                l = i;
                m = mpp[tar-a[i]];
                maxi = abs(l-m);
            }
        }
        mpp[a[i]] = i;
    }
    if ( l == -1 && m == -1 ) 
    cout << "IMPOSSIBLE"    << endl;
    else   cout << m+1 << " " << l+1 << endl;
}