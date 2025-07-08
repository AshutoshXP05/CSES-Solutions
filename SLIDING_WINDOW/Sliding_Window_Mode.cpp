
//  Using Hash Map --->

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



void solve () {
    
    ll n, k;
    cin >> n >> k;
    map<ll,int> mpp;
    map<int,set<ll>> freq;

    vector<ll> arr(n);
    for ( int i=0; i<n; i++ ) cin >> arr[i];

    int l = 0;
    int r = k-1;

    for  (int i=l; i<=r; i++ ) {
        int val = arr[i];
        int oldFreq = mpp[val];
        if ( oldFreq > 0 ) 
        {freq[oldFreq].erase(val);
        if ( freq[oldFreq].empty() ) freq.erase(oldFreq);}
        
        mpp[arr[i]]++;
        freq[mpp[arr[i]]].insert(val);
         
    }

    while  (true) {

        cout << *freq.rbegin()->second.begin()<< " ";

        int oldFreq = mpp[arr[l]];
        freq[oldFreq].erase(arr[l]);
         if ( freq[oldFreq].empty() ) freq.erase(oldFreq);

        mpp[arr[l]]--;
        if ( mpp[arr[l]] == 0 ) mpp.erase(arr[l]); 
       else  freq[mpp[arr[l]]].insert(arr[l]);

        r++;
        if ( r == n ) break;

        int oldFreqOfR = mpp[arr[r]];
        freq[oldFreqOfR].erase(arr[r]);
        if ( freq[oldFreqOfR].empty() ) freq.erase(oldFreqOfR);

        mpp[arr[r]]++;
        freq[mpp[arr[r]]].insert(arr[r]);


       l++;

    }

    return ;
}

