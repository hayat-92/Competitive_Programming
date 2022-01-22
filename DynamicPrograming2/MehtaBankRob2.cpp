#include <iostream>
#include <utility>
using namespace std;
#include <algorithm>

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        long long *profit = new long long[N];
        long long *weight = new long long[N];
        for (int i = 0; i < N; i++)
        {
            cin >> profit[i];
        }

        for (int i = 0; i < N; i++)
        {
            cin >> weight[i];
        }

        pair<long long, long long> *arr = new pair<long long, long long>[N];
        for (int i = 0; i < N; i++)
        {
            arr[i].first = profit[i];
            arr[i].second = weight[i];
        }

        sort(arr, arr + N);

        // int prime[10] = {23, 19, 17, 13, 11, 7, 5, 3, 2, 1};
        long long ***dp = new long long **[2];
        for (int i = 0; i < 2; i++)
        {
            dp[i] = new long long *[N + 1];
            for (int j = 0; j <= N; j++)
            {
                dp[i][j] = new long long[W + 1];
                for (int k = 0; k <= W; k++)
                {
                    dp[i][j][k] = 0;
                }
            }
        }

        int primes[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                dp[0][i][j] = dp[0][i - 1][j];

                if (j >= arr[i - 1].second)
                {
                    dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j - arr[i - 1].second] + arr[i - 1].first);
                }
            }
        }

        for (int prime = 1; prime <= 10; prime++)
        {
            int p = prime % 2;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= W; j++)
                {
                    dp[p][i][j] = dp[p][i - 1][j];
                    if (j >= arr[i - 1].second)
                    {
                        dp[p][i][j] = max(dp[p][i][j], max(dp[p][i - 1][j - arr[i - 1].second] + arr[i - 1].first, dp[p ^ 1][i - 1][j - arr[i - 1].second] + arr[i - 1].first * primes[prime]));
                    }
                }
            }
        }

        cout << dp[0][N][W]<<endl;
    }
}