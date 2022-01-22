#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;

ll fXn(string s1, string s2, ll l1, ll l2, ll **dp){

    if(s1.length()==0 && s2.length()==0){
        return 0;
    }

    if(s1.length()<=0){
        return s2.length();
    }
    if(s2.length()<=0){
        return s1.length();
    }

    if(dp[l1][l2]>-1){
        return dp[l1][l2];
    }

    ll temp;

    if(s1[0]==s2[0]){
        temp=1+fXn(s1.substr(1, s1.length()-1), s2.substr(1, s2.length()-1),l1-1, l2-1, dp);
    }else{
        ll t1=1+fXn(s1.substr(1, s1.length()-1), s2, l1-1, l2, dp);
        ll t2=1+fXn(s1, s2.substr(1, s2.length()-1), l1, l2-1, dp);
        temp=min(t1, t2);
    }
    dp[l1][l2]=temp;
    return temp;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1;
        cin>>s2;
        ll l1=s1.length();
        ll l2=s2.length();
        ll **dp=new ll *[l1+1];
        for(ll i=0; i<=l1; i++){
            dp[i]=new ll[l2+1];
            for(ll j=0; j<=l2; j++){
                dp[i][j]=-1;
            }
        }
        cout<<fXn(s1, s2, s1.length(), s2.length(),dp)<<endl;
    }
    return 0;
}