#include <iostream>
using namespace std;

bool knapsumIter(int *arr, int x, int n)
{
    bool **dp = new bool *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new bool[x + 1];
    }

    for (int j = 0; j <= x; j++)
    {
        dp[0][j] = false;
    }

    for (int j = 0; j <= n; j++)
    {
        dp[j][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=x; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][x];
}

bool knapSum(int *arr, int x, int n, bool **dp)
{

    if (x < 0)
    {
        return false;
    }

    if (x == 0)
    {
        return true;
    }

    if (n == 0)
    {
        if (x == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (dp[n][x])
    {
        return true;
    }

    bool fnl;
    if (x - arr[0] >= 0)
    {
        fnl = (knapSum(arr + 1, x, n - 1, dp) || knapSum(arr + 1, x - arr[0], n - 1, dp));
    }
    else
    {
        fnl = knapSum(arr + 1, x, n - 1, dp);
    }

    dp[n][x] = fnl;
    return fnl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int x;
        cin >> x;

        bool **dp = new bool *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = new bool[x + 1];
            for (int j = 0; j <= x; j++)
            {
                dp[i][j] = false;
            }
        }
        bool fnl = knapsumIter(arr, x, n);
        if (fnl)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}