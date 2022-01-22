#include <iostream>
#include <algorithm>
using namespace std;

int fXn(int **arr, int **dp, int N, int M)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            if (j == 0)
            {
                x = min(dp[i - 1][j], dp[i - 1][j + 1]) + arr[i - 1][j];
            }
            else if (j == M - 1)
            {
                x = min(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i - 1][j];
            }
            else
            {
                x = min(dp[i - 1][j], min(dp[i - 1][j + 1], dp[i - 1][j - 1])) + arr[i - 1][j];
            }
            dp[i][j] = x;
        }
    }

    int Fmin = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        Fmin = min(Fmin, dp[N][i]);
    }

    return Fmin;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int **arr = new int *[N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = new int[M];
            for (int j = 0; j < M; j++)
            {
                cin >> arr[i][j];
            }
        }

        int **dp = new int *[N + 1];
        for (int i = 0; i <= N; i++)
        {
            dp[i] = new int[M];
            for (int j = 0; j < M; j++)
            {
                dp[i][j] = 0;
            }
        }

        cout << fXn(arr, dp, N, M) << endl;
    }
    return 0;
}