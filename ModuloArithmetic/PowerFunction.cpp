#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

ll powx(ll x, ll p){
    ll m=pow(10,9)+7;
    ll px=1;
    for(int i=0; i<p; i++){
        px=(px*x)%m;
    }

    return px;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int x,p;
        cin>>x>>p;
        cout<<powx(x,p)<<endl;
    }
    return 0;
}