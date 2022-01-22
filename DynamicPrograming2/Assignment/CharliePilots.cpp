#include <iostream>
#include <algorithm>
using namespace std;

int fXn(int *cp, int *as, int n, int x, int **dp)
{
    if (n <= 0)
    {
        return 0;
    }

    if (dp[n][x] > -1)
    {
        return dp[n][x];
    }

    int fnl;

    if (x == 0)
    {
        fnl = (as[0] + fXn(cp + 1, as + 1, n - 1, x + 1, dp));
    }
    else if (x == n)
    {
        fnl = (cp[0] + fXn(cp + 1, as + 1, n - 1, x - 1, dp));
    }
    else
    {
        int temp1 = as[0] + fXn(cp + 1, as + 1, n - 1, x + 1, dp);
        int temp2 = cp[0] + fXn(cp + 1, as + 1, n - 1, x - 1, dp);
        fnl = min(temp1, temp2);
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
        int *cp = new int[n];
        int *as = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> cp[i] >> as[i];
        }

        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[(n / 2) + 1];
            for (int j = 0; j <= n / 2; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << fXn(cp, as, n, 0, dp) << endl;
    }
    return 0;
}