#include<iostream>
using namespace std;
typedef long long ll;

ll m=pow(10,9)+7;

ll fXn(ll open, ll close, ll total, bool *barr, ll **dp){
    if(open>(total/2) || close>(total/2)){
        return 0;
    }
    if(open==(total/2) && close==(total/2)){
        return 1;
    }

    if(dp[open][close]>-1){
        return dp[open][close];
    }

    ll curIn=open+close;
    ll fnl;

    if(open==close || barr[curIn]==true){
        fnl= fXn(open+1, close, total, barr, dp);
    }else if(open==(total/2)){
        fnl= fXn(open, close+1, total, barr, dp);
    }else{
        fnl= fXn(open+1, close, total, barr, dp)+fXn(open, close+1, total, barr, dp);
    }

    dp[open][close]=(fnl)%m;
    return fnl;
}

ll main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll *arr=new ll[k];
        for(ll i=0; i<k; i++){
            cin>>arr[i];
        }

        bool *barr=new bool[2*n];
        for(ll i=0; i<2*n; i++){
             barr[i]=false;
        }
        for(ll i=0; i<k; i++){
            barr[arr[i]-1]=true;
        }

        

        ll **dp = new ll *[n + 1];
        for (ll i = 0; i <= n; i++)
        {
            dp[i] = new ll[n + 1];
            for (ll j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout<<fXn(0, 0, 2*n, barr, dp)<<endl;
    }
    return 0;
}