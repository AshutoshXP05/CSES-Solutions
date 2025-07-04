
// Application of Lazy Propogation --->

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve();
#define MOD 1000000007 // MODULUS
#define PI 3.1415926535897932384626433832795
#define pb push_back // PUSH _ BACK
#define fi first     // FIRST
#define se second    // SECOND
#define endl '\n'    //  endl se fast hota hai isly we use /N

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
#define yes cout << "YES\n"; //  For yes
#define no cout << "NO\n";   // For No

int main()
{
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

ll n;
vector<ll> arr;
vector<ll> segTree;
vector<ll> lazy;


void buildTree(ll i, ll l, ll r) {
    if ( l == r ) {
        segTree[i] = arr[l];
        return;
    }

    ll mid = l + ( r - l ) / 2;
    buildTree(2*i+1, l, mid);
    buildTree(2*i+2, mid+1, r) ;

    segTree[i] = (segTree[2*i+1] + segTree[2*i+2]);

}


ll printKthValue(ll i, ll l, ll r, ll ind ) {
    // check in lazy array 
    if ( lazy[i] != 0 ) {
        segTree[i] += (r-l+1) * lazy[i] * 1LL;
        
        if ( l != r ) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    if ( l == r  ) return segTree[i];

    int mid = l + ( r - l ) / 2;
    if ( mid >= ind ) {
       return printKthValue(2*i+1, l, mid, ind);
    }
    else {
      return  printKthValue(2*i+2, mid+1, r, ind);
    }

}


void updateRangeQueries ( ll i, ll l, ll r, ll start, ll end, ll val ) {
    
    // check in lazy array 
    if ( lazy[i] != 0 ) {
        segTree[i] += (r-l+1) * lazy[i] * 1LL;
        
        if ( l != r ) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    // case 1 : Out of bound range 
    if ( r < start || l > end || l > r  ) {
        return;
    }

    // Case 2 : In the range 
    if ( l >= start && r <= end ) {
        segTree[i] += ( r - l + 1 ) * val * 1LL;
        if ( l != r ) {
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }

    // Case 3 : Overlapping Range 
    ll mid = l + ( r - l ) / 2;
    updateRangeQueries(2*i+1, l, mid, start, end, val );
    updateRangeQueries(2*i+2, mid+1, r, start, end, val );

     segTree[i] = (segTree[2*i+1] + segTree[2*i+2]);

}


void solve() {
    ll q;
    cin >> n >> q;

    arr.resize(n);
    segTree.resize(4*n);
    lazy.resize(4*n, 0);

    for ( ll i=0; i<n; i++ ) cin >> arr[i] ;

    buildTree(0, 0, n-1);

    while ( q-- ) {

        ll type ;
        cin >> type;
       
        if ( type == 1 ) {
            ll a, b ,u;
            cin >> a >> b >> u;
            updateRangeQueries(0, 0, n-1, a-1, b-1, u);
        }

        else {
            ll k;
            cin >> k;

            cout << printKthValue(0, 0, n-1, k-1) << endl;
        }
 
    }
}