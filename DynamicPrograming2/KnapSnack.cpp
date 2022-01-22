#include <iostream>
#include <algorithm>
using namespace std;

int knapsnack(int n, int *w, int *v, int W, int **dp)
{
    if (W <= 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 0;
    }

    if(dp[n][W]>-1){
        return dp[n][W];
    }

    if ((W - w[0]) >= 0)
    {
        int val = v[0] + knapsnack(n - 1, w + 1, v + 1, W - w[0], dp);
        int val2 = knapsnack(n - 1, w + 1, v + 1, W, dp);
        int fnl=max(val, val2);
        dp[n][W]=fnl;
        return fnl;
    }else{
        return knapsnack(n-1, w+1, v+1, W, dp);
        // return 0;
    }

    
}
int main()
{
    int n;
    cin >> n;
    int *w = new int[n];
    int *v = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int W;
    cin >> W;

    int **dp=new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i]=new int[W+1];
        for(int j=0; j<W+1; j++){
            dp[i][j]=-1;
        }
    }
    cout << knapsnack(n, w, v, W, dp) << endl;
    return 0;
}