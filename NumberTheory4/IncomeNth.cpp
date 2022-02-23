#include<iostream>
using namespace std;
#define m 1000000007
typedef long long ll;

#define mod 1000000007


// void multiply(ll A[2][2], ll M[2][2]){
//     ll fValue=((A[0][0]*M[0][0])%mod+(A[0][1]*M[1][0])%mod)%mod;
//     ll sValue=((A[0][0]*M[0][1])%mod+(A[0][1]*M[1][1])%mod)%mod;
//     ll tValue=((A[1][0]*M[0][0])%mod+(A[1][1]*M[1][0])%mod)%mod;
//     ll lValue=((A[1][0]*M[0][1])%mod +(A[1][1]*M[1][1])%mod)%mod;
//     A[0][0]=fValue%mod;
//     A[0][1]=sValue%mod;
//     A[1][0]=tValue%mod;
//     A[1][1]=lValue%mod;
// }
void multiply(ll A[2][2], ll M[2][2]){
    int MOD = mod - 1;
    ll fValue=((A[0][0]*M[0][0])%MOD+(A[0][1]*M[1][0])%MOD)%MOD;
    ll sValue=((A[0][0]*M[0][1])%MOD+(A[0][1]*M[1][1])%MOD)%MOD;
    ll tValue=((A[1][0]*M[0][0])%MOD+(A[1][1]*M[1][0])%MOD)%MOD;
    ll lValue=((A[1][0]*M[0][1])%MOD +(A[1][1]*M[1][1])%MOD)%MOD;
    A[0][0]=fValue%MOD;
    A[0][1]=sValue%MOD;
    A[1][0]=tValue%MOD;
    A[1][1]=lValue%MOD;
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


ll modExp(ll a, ll b, ll c){
    if(a==0){
        return 0;
    }

    if(b==0){
        return 1;
    }

    long ans;
    if(b%2==0){ 
        //b is even
        long smallAns=modExp(a, b/2, c);
        ans=(smallAns*smallAns)%c;
    }else{
        long smallAns=modExp(a, b-1, c);
        ans=a%c;
        ans=(ans*smallAns)%c;
    }

    return ll((ans+c)%c);
}

ll fxn(ll f0, ll f1, ll N){
    ll n1=fib(N-1);
    ll n=fib(N);
    ll s1 =modExp(f0, n1, m)%m;
    ll s2=modExp(f1, n, m)%m;
    return (s1*s2)%m;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll f0, f1, N;
        cin>>f0>>f1>>N;
        ll val=fxn(f0+1, f1+1, N)%m;
        cout<<((val-1)%m+m)%m<<endl;
    }
    return 0;
}