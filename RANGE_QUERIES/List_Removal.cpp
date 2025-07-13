
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
vector<ll> position;

void build(int i, int l, int r) {
    if ( l == r ) {
        segTree[i] = 1;
        return;
    }
    int mid = l + ( r - l ) / 2;
    build (2*i+1, l, mid);
    build(2*i+2, mid+1, r);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}


void update(int i, int l, int r, int ind) {
    if ( l == r ) {
        segTree[i] = 0;
        return;
    }

    int mid = l + ( r - l ) / 2;
    if ( mid >= ind ) {
         update(2*i+1, l, mid, ind);
    }
    else {
          update(2*i+2, mid+1, r, ind);
    }
     segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}


int KthQuery(int i, int l, int r, int k ) {
    if ( l == r ) return l ;
    int mid = l + ( r - l ) / 2;
    if ( segTree[2*i+1] >= k ) {
       return KthQuery(2*i+1, l, mid, k );
    }
    else {
       return KthQuery(2*i+2, mid+1, r, k - segTree[2*i+1] );
    }
}

void solve () {
    ll n;
    cin >> n;

    arr.resize(n);
    for ( int i=0; i<n; i++ ) cin >> arr[i];
    position.resize(n);
    for ( int i=0; i<n; i++ ) cin >> position[i];

    segTree.resize(4*n);

     build(0, 0, n-1) ;

     for ( int i=0; i<n; i++ ) {
       int arrInd = KthQuery(0, 0, n-1, position[i]);
        cout << arr[arrInd]  << " " ;
        update(0, 0, n-1, arrInd);
     }

      cout << endl;
}