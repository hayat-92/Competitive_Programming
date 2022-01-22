#include<iostream>
#include<algorithm>
using namespace std;

int maxPoint(int *arr, int n){
    int *freq=new int[1001];
    for(int i=0; i<1001; i++){
        freq[i]=0;
    }
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    // sort(arr, arr+n);

    int *dp=new int[1001];
    dp[0]=0;
    dp[1]=freq[1];
    // dp[2]=2;
    for(int i=2; i<1001; i++){
        dp[i]=max((dp[i-2]+i*freq[i]), dp[i-1]);
    }

     int maximum=dp[1000];
    delete[] freq;
    delete[] dp;
    return maximum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<maxPoint(arr, n)<<endl;
    }
    return 0;
}