
// USE OF BINARY LIFTING CONCEPT --->

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve();
#define MOD 1000000007         // MODULUS 
#define PI 3.1415926535897932384626433832795
#define pb push_back       // PUSH _ BACK 
#define fi first         // FIRST 
#define se second    //SECOND 
#define endl '\n'      //  endl se fast hota hai isly we use /N 

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
#define yes cout<<"YES\n";              //  For yes 
#define no cout<<"NO\n";               // For No


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    // long long t;          // Test cases wala .. 
    // cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}

vector<vector<ll>> dp;
vector<ll> arr;
int LOG ;

void precomputeDP ( int node ) {
     dp.resize(LOG, vector<ll>(node+1));

     for ( int i=1; i<=node; i++ ) {
        dp[0][i] = arr[i];
     }

     for ( int i=1; i<LOG; i++ ) {
        for ( int j=1; j<=node; j++ ) {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
     }

}

int value ( int node,  int k ) {
    int cnt  = 0;
    while ( k ) {
        int lastBit = k & 1;
        k >>= 1;
        if ( lastBit == 1 ){
            node = dp[cnt][node]; 
        }
        //  if (node == 0) break;
        cnt++;
        
    }
    return node;
}

void solve(){
    
    ll n, q;
    cin >> n >> q;
    arr.resize(n+1);
    for ( int i=1; i<=n; i++ ) cin >> arr[i];

    LOG = 30;

    vector<int> ans;
    precomputeDP(n);

    while ( q-- ) {

       int a, b;
       cin >> a >> b;

       cout << value(a,b) << '\n';

    }

}