#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int fXn(string b1, string b2, int k, int ***dp){

    if(k==0){
        return 0;
    }

    if(b1.length() ==0 || b2.length()==0){
        return 0;
        
    }
    int n=b1.length();
    int n2=b2.length();

    if(dp[n][n2][k]>-1){
        return dp[n][n2][k];
    }

    int fnl=0;

    if(b1[0]==b2[0]){
        int t1=b1[0]+fXn(b1.substr(1), b2.substr(1), k-1, dp);
        if(t1-b1[0]==0 && k>1){
            t1=0;
        }
        int t2=fXn(b1.substr(1), b2, k, dp);
        int t3=fXn(b1, b2.substr(1), k, dp);
        fnl=max(t1, max(t2, t3));
    }else{
        int t2=fXn(b1.substr(1), b2, k, dp);
        int t3=fXn(b1, b2.substr(1), k, dp);
        fnl=max(t2, t3);
    }

    dp[n][n2][k]=fnl;

    return fnl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string b1,b2;
        int k;
        cin>>b1>>b2;
        cin>>k;
        int ***dp=new int**[b1.length()+1];
        for(int i=0; i<b1.length()+1; i++){
            dp[i]=new int*[b2.length()+1];
            for(int j=0; j<=b2.length(); j++){
                dp[i][j]=new int[k+1];
                for(int x=0;x<=k; x++){
                    dp[i][j][x]=-1;
                }
            }
        }

        cout<<fXn(b1, b2, k, dp)<<endl;
    }
    return 0;
}