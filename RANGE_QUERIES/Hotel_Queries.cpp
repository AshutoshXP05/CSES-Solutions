
// Application of Segment Tree --->

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

vector<ll> segTree;
vector<ll> arr;
vector<ll> query;

void build(int i, int l, int r) {
    if ( l == r ) {
        segTree[i] = arr[l];
        return;
    }
    int mid = l + ( r - l ) / 2;
    build (2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
}


void update(int i, int l, int r, int ind, int val) {
    if ( l == r ) {
        segTree[i] -= val ;
        return;
    }

    int mid = l + ( r - l ) / 2;
    if (  mid >= ind ) {
         update(2*i+1, l, mid, ind, val);
    }
    else {
          update(2*i+2, mid+1, r, ind, val);
    }
     segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
}


int KthQuery(int i, int l, int r, int val ) {
     if ( l == r  ) {
     if ( segTree[i] >= val ) return l ;
     else return INT_MAX;
     }

     int mid = l + ( r - l ) / 2;
     int left = INT_MAX;
     int right = INT_MAX;
    if ( segTree[2*i+1] >= val ) {
         left = KthQuery(2*i+1, l, mid, val);
    }
    else {
        right = KthQuery(2*i+2, mid+1, r, val);
    }
    return min(left, right) ;
}

void solve () {
    ll n, k;
    cin >> n >> k ;

    arr.resize(n);
    for ( int i=0; i<n; i++ ) cin >> arr[i];

    query.resize(k);
    for ( int i=0; i<k; i++ ) cin >> query[i] ;
  
    segTree.resize(4*n);

     build(0, 0, n-1) ;

     for ( int i=0; i<k; i++ ) {
    int val = query[i] ;
       int ind = KthQuery(0, 0, n-1, val);
       if ( ind == INT_MAX ){
        cout << 0 << " ";
       }
       else {
        cout << ind+1 << " ";
        update(0, 0, n-1, ind, val);
       }

     }

      cout << endl;
}