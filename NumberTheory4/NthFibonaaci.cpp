#include<iostream>
using namespace std;
typedef long long ll;
#define mod 1000000007


void multiply(ll A[2][2], ll M[2][2]){
    ll fValue=((A[0][0]*M[0][0])%mod+(A[0][1]*M[1][0])%mod)%mod;
    ll sValue=((A[0][0]*M[0][1])%mod+(A[0][1]*M[1][1])%mod)%mod;
    ll tValue=((A[1][0]*M[0][0])%mod+(A[1][1]*M[1][0])%mod)%mod;
    ll lValue=((A[1][0]*M[0][1])%mod +(A[1][1]*M[1][1])%mod)%mod;
    A[0][0]=fValue%mod;
    A[0][1]=sValue%mod;
    A[1][0]=tValue%mod;
    A[1][1]=lValue%mod;
}

void power(ll A[2][2], ll n){
    if(n==0 || n==1){
        return;
    }

    power(A, n/2);

    multiply(A,A);
    if((n%2) != 0){
        ll M[2][2]={{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

ll fib(ll n){
    ll A[2][2]={{1, 1}, {1, 0}};
    if(n==0){
        return 0;
    }

    power(A, n-1);
    return A[0][0]%mod;
}

int main(){
    cout<<fib(8)<<endl;
    return 0;
}