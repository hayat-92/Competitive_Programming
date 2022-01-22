#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;

ll m = pow(10, 9) + 7;


ll fXn(string str){
    ll n=str.length();
    ll *dp=new ll[n+1];
    ll *alpIn=new ll[256];
    for(ll i=0; i<256; i++){
        alpIn[i]=-1;
    }
    dp[0]=1;
    for(ll i=1; i<=n; i++){
        dp[i]=(2*dp[i-1])%m;
        if(alpIn[str[i-1]]!=-1){
            dp[i]=(dp[i]-dp[alpIn[str[i-1]]])%m;
        }

        alpIn[str[i-1]]=i-1;
    }

    return dp[n]%m;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<fXn(str)<<endl;
    }
    return 0;
}

