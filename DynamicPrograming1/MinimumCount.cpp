#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPerfectSquare(int x)
{

    if (x >= 0) {
 
        int sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

int MinCount(int n, int *dp){
    if(isPerfectSquare(n)){
        return 1;
    }

    if(n<=3){
        return n;
    }
    if(dp[n]>0){
        return dp[n];
    }

    int count=n;
    for(int i=1; i*i<=n; i++){
        count= min(count, 1+MinCount(n-i*i, dp));
    }

    dp[n]=count;
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *dp=new int[n+1];
        for(int i=0; i<n+1; i++){
            dp[i]=0;
        }
        cout<<MinCount(n, dp)<<endl;;
    }
    return 0;
}