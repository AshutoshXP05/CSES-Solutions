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

#define en cout<<endl;       //  for new line 

#define is(x) cout<<" is: "<<x<<endl; 
#define sp <<" "<<      // for space 
typedef long long ll;
#define all(x) (x).begin(), (x).end()       // used in sort 
#define present(c,x) ((c).find(x) != (c).end())       // used to check whether present or not 
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(long long a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }         // To check Prime Number 

ll expo(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % MOD; a = (a * a) % MOD; b = b >> 1;} return res;}          // Code of a ^ b (power )

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// ll expo(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % MOD; a = (a * a) % MOD; b = b >> 1;} return res;} 

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
    long long t;          // Test cases wala .. 
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}

void solve(){
    long long n,i,j,k,count=0,ans;
    cin>>n;
    vector<long long> a(n);
    // f(i,0,n)cin>>a[i];               // I zero se n tak ja raha hai 
      
    // cout<<count<<endl;
}