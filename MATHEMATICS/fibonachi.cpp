#include<bits/stdc++.h>
using namespace std;

void matmul (long long arr[2][2], long long brr[2][2]) {
    long long p = (arr[0][0] * brr[0][0] + arr[0][1] * brr[1][0]) % 1000000007;
    long long q = (arr[0][0] * brr[0][1] + arr[0][1] * brr[1][1]) % 1000000007;
    long long r = (arr[1][0] * brr[0][0] + arr[1][1] * brr[1][0]) % 1000000007;
    long long s = (arr[1][0] * brr[0][1] + arr[1][1] * brr[1][1]) % 1000000007;

    arr[0][0] = p;
    arr[0][1] = q;
    arr[1][0] = r;
    arr[1][1] = s;
}

void powermat ( long long arr[2][2], long long n) {
    if ( n == 0 || n == 1 ) return;
    long long brr[2][2] = {{1,1}, {1,0}};
    powermat(arr,n/2);
    matmul ( arr, arr);

    if ( n % 2 != 0 ) {
        matmul ( arr, brr);
    }

}

long long fib(long long n) {
   long long arr[2][2] = {{1,1},{1,0}};
   if ( n == 0) return 0;
   if ( n == 1 ) return 1;
   powermat( arr, n-1);

return arr[0][0];
}

int main () {
    long long n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}



