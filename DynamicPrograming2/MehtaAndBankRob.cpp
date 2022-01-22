#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;


int RobFxn(pair<long long, long long> *arr, int *prime, int pVal, int N, int W, int ***dp){
    if(pVal==0){
        return 0;
    }
    if(N==0){
        return 0;
    }

    if(W<=0){
        return 0;
    }

    if(dp[pVal][N][W]>-1){
        return dp[pVal][N][W];
    }
    int currMax;
    if(W-arr[0].second>=0){
        int temp=RobFxn(arr+1, prime, pVal, N-1, W, dp);
        int temp1=RobFxn(arr+1, prime, pVal, N-1, W-arr[0].second, dp) + (arr[0].first);
        int temp2=RobFxn(arr+1, prime+1, pVal-1, N-1, W-arr[0].second, dp) +(prime[0]*arr[0].first);
        currMax=max(temp,max(temp1, temp2));
    }else{
        int temp=RobFxn(arr+1, prime, pVal, N-1, W, dp);
        currMax=temp;
    }

    dp[pVal][N][W]=currMax;
    return currMax;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,W;
        cin>>N>>W;
        int *profit=new int[N];
        int *weight=new int[N];
        for(int i=0; i<N; i++){
            cin>>profit[i];
        }

        for(int i=0; i<N; i++){
            cin>>weight[i];
        }

        pair<long long, long long> *arr=new pair<long long, long long>[N];
        for(int i=0; i<N; i++){
            arr[i].first=profit[i];
            arr[i].second=weight[i];
        }

        sort(arr, arr+N);



        int prime[11]={1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int prime[10]={23, 19, 17, 13,11 , 7, 5, 3, 2, 1};
        int ***dp=new int**[10];
        for(int i=0; i<=10;i++){
            dp[i]=new int*[N+1];
            for(int j=0; j<=N; j++){
                dp[i][j]=new int[W+1];
                for(int k=0; k<=W; k++){
                    dp[i][j][k]=-1;
                }
            }
        }

        cout<<RobFxn(arr,prime, 9, N, W, dp)<<endl;
    }
    return 0;
}