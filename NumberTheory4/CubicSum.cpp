#include<iostream>
#include<string>
using namespace std;
typedef long long ll;

ll fxn(ll a, string b, ll m){
    ll result=1;
    ll temp=a;
    for(ll i=b.length()-1;i>=0; i--){
        if(b[i]=='1'){
            result=(result*temp)%m;
        }else if(b[i]=='2'){
            result=(((result*temp)%m)*temp)%m;
        }

        temp=(((temp*temp)%m)*temp)%m;
    }
    return result%m;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, m;
        string b;
        cin>>a>>b>>m;
        cout<<fxn(a, b, m)<<endl;
    }
    return 0;
}