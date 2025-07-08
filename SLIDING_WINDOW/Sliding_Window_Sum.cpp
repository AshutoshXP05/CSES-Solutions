
//  Sliding Window with huge Constraint --->

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
    solve();
    return 0;
}

void solve()
{
    ull n, k, a, b, c, d, x ;
    cin >> n >> k;
    cin >> x >> a >> b >> c;

     vector<ull> window(k);

     ull sum = 0;

     for ( ull i=0; i<k; i++ ) { 
         window[i] = x;
         sum += x ;
         x = ( a * x + b ) % c ;
     }

      ull ans = sum ;

     for ( ull i = k; i<n; i++ ) {
        ull index = i%k; 
        sum = sum - window[index] + x ;
        window[index] = x;
        ans ^= sum;

         x = ( a * x + b ) % c ;
     }

       cout << ans << endl;
}