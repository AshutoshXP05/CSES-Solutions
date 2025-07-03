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
    long long n,i,j,k=1,count=0,ans;
        string str;
        map < char, int > mpp;
        cin >> str;
        int l = str.length();
        if ( l == 1 ) {
            cout << str << endl;
            return;
        }
        f(i,0,l) {
            mpp[str[i]] ++;
        }
        i = 0;
        j = l-1;
        // m = 1;
        // n = 1;
        string temp(l, ' ');
        bool checkNoOfOdd = true;
 
         for ( auto &p : mpp ) {
             if ( p.se % 2 == 1 ) {

                if ( p.se == 1 && checkNoOfOdd ) {
                    temp[l/2] = p.fi;
                    checkNoOfOdd = false;
                }
                else if (checkNoOfOdd) {
                 while (( (p.se - 1) != 0)) {
                     temp[i] = p.fi;
                     temp[j] = p.fi;
                     i ++;
                     j--;
                     temp[l/2] = p.fi;
                     p.se -= 2;
                     
                 }
                 checkNoOfOdd = false;
                }
                else  {
                    cout << "NO SOLUTION" << endl;
                    return;
                }  
             }
             else if (  p.se % 2 == 0 ){
                
                while (p.se  != 0 ) {
                    temp[i] = p.fi;
                    temp[j] = p.fi;
                    i ++;
                    j--;
                
                    p.se -= 2;
                   
                }
             }
             
         }
         cout << temp << endl;
}