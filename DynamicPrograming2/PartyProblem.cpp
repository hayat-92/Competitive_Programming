#include<iostream>
#include<algorithm>
using namespace std;

void knapFun(int *val, int *wt, int n, int W){
    int **dp=new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i]=new int[W+1];
    }

    for(int i=0; i<=W; i++){
        dp[0][i]=0;
    }

    for(int i=0; i<=n; i++){
        dp[i][0]=0;
    }

    for(int i=1; i<=n; i++){
        for(int w=1; w<=W; w++){
            dp[i][w]=dp[i-1][w];
            if(wt[i-1]<=w){
                dp[i][w]=max(dp[i][w], val[i-1]+dp[i-1][w-wt[i-1]]);
            }
        }
    }

    int ans=dp[n][W];
    int weigh=INT_MAX;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(dp[i][j]==ans){
                weigh=min(weigh, j);
            }

        }
    }

    
    cout<<weigh<<" "<<ans<<endl;
}

int main(){
    int N;
    cin>>N;
    int *cost=new int[N];
    for(int i=0; i<N; i++){
        cin>>cost[i];
    }

    int *fun =new int[N];
    for(int i=0; i<N; i++){
        cin>>fun[i];
    }

    int W;
    cin>>W;

    knapFun(fun, cost, N, W);
    return 0;
}