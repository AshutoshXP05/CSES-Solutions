
// Application of 2D Prefix Sum --->

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

ll n ;
vector<vector<int>> prefixMat;


void calculatePrefixSum(vector<vector<int>> &vec) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefixMat[i][j] = vec[i][j]
                            + prefixMat[i - 1][j]
                            + prefixMat[i][j - 1]
                            - prefixMat[i - 1][j - 1];
        }
    }
}

 
void solve () {
    ll q;
    cin >> n >> q;

    vector<vector<int>> vec(n+1, vector<int> (n+1)) ;
    for ( int i=1; i<=n; i++ ) {
        for ( int j=1; j<=n; j++ ) {
            char ch ;
            cin >> ch;
            if ( ch == '.' ) vec[i][j] = 0;
            else vec[i][j] = 1;
        }
    }

   prefixMat.resize(n+1, vector<int>(n+1, 0));

    calculatePrefixSum(vec);

    while ( q-- ) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int total = prefixMat[y2][x2];
        int top = prefixMat[y1 - 1][x2];
        int left = prefixMat[y2][x1 - 1];
        int overlap = prefixMat[y1 - 1][x1 - 1];

        cout << total - top - left + overlap << '\n';
    }
}