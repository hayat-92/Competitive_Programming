#include<iostream>
#include<algorithm>
using namespace std;

int lootSum(int *arr, int n){
    int *dp=new int [n];
    dp[0]=arr[0];
    dp[1]=max(dp[0], arr[1]);
    for(int i=2; i<n; i++){
        dp[i]=max((arr[i]+dp[i-2]), dp[i-1]);
    }

    int fnl=dp[n-1];

    delete [] dp;
    return fnl;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<lootSum(arr, n)<<endl;
    delete [] arr;
    return 0;
}