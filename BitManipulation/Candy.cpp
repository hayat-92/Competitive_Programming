#include<iostream>
using namespace std;

int fXn(int **likes, int n, int *dp){

    for(int mask=0; mask<((1<<n)-1); mask++){
        int temp=mask;
        int k=0;
        while(temp>0){
            if((temp%2)==1){
                k++;
            }
            temp=temp/2;
        }

        for(int j=0; j<n; j++){
            if(!(mask&(1<<j)) && likes[k][j]){
                dp[mask|(1<<j)]+=(dp[mask]);
            }
        }
    }

    return dp[(1<<n)-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int **likes=new int*[n];
        for(int i=0; i<n; i++){
            likes[i]=new int[n];
            for(int j=0; j<n; j++){
                cin>>likes[i][j];
            }
        }
        int *dp=new int[(1<<n)];
        dp[0]=1;
        for(int i=1; i<(1<<n); i++){
            dp[i]=0;
        }

        cout<<fXn(likes, n, dp);

    }
    return 0;
}