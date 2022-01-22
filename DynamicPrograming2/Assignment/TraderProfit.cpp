#include<iostream>
#include<algorithm>
using namespace std;

int fXn(int *arr, int k, int n){
    int **dp=new int*[k+1];
    for(int i=0; i<=k;i++){
        dp[i]=new int[n];
        for(int j=0; j<n; j++){
            dp[i][j]=0;
        }
    }

    for(int i=1; i<=k; i++){
        for(int j=1; j<n; j++){
            int x=dp[i][j-1];
            for(int k=0; k<j; k++){
                x=max(x, (dp[i-1][k]+(arr[j]-arr[k])));
                dp[i][j]=x;
            }
        }
    }

    return dp[k][n-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        cout<<fXn(arr, k, n)<<endl;
    }
    return 0;
}