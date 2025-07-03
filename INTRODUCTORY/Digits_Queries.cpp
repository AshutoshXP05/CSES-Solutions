// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;

// int Q;
// ll K;

// ll pow10(int x){
//     ll res = 1;
//     for(int i = 0; i < x; i++)
//         res *= 10;
//     return res;
// }

// int solve(ll N){
//     if(N < 9)   return (int) N+1;

//     int len = 1;
//     while(9 * pow10(len-1) * len < N){
//         N -= 9 * pow10(len-1) * len;
//         len++;
//     }

//     string S = to_string(pow10(len-1) + N/len);
//     return (int) (S[N%len] - '0');
// }

// int main(){
//     scanf("%d", &Q);
//     for(int q = 0; q < Q; q++){
//         scanf("%lld", &K);
//         printf("%d\n", solve(K-1));
//     }
// }


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector< ll > arr(19,1);
void precompute () {
// long long i = 1;
    for ( long long i=1; i<19; i++ ) {
        arr[i] = arr[i-1] * 10;
    }
}

void solve () {
    // precompute();
     ll k ;
     cin >> k;
     ll digits = 0;
     ll totaldigits = 0;
     ll i = 1;
     for ( ; i<19; i++ ) {
         digits = ( arr[i] - arr[i-1] ) * i ;
          if (( totaldigits + digits) >= k ) break;
         totaldigits += digits;
        
     }
      ll startingValue = arr[i-1];
     ll required = k  - totaldigits;
     ll actualNumber = startingValue + ( (required-1)/i);
     string str = to_string(actualNumber);
     int rem = (required-1)%i;
     cout << str[rem] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed; 
    ll t;
    cin >> t;
    // vector< ll > arr(19,1);
    // for ( ll i; i<19; i++ ) {
    //     arr[i] = arr[i-1] * 10;
    // }
    precompute();
    while ( t -- )    
    solve();   
    return 0;
}