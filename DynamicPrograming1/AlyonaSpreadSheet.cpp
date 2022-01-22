#include <iostream>
#include <algorithm>
using namespace std;

void minElem(int **dp, int n, int m, int *fnl)
{

    int k = 1;
    for (int i = 1; i < n + 1; i++)
    {
        int myn = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            myn = min(myn, dp[i][j]);
        }
        fnl[k++] = myn;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int **arr = new int *[n + 1];
        // int *r2=new int[m];
        // arr[0]=new int[m+1];
        for (int i = 0; i < n + 1; i++)
        {

            int *rw = new int[m];
            arr[i] = rw;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <m; j++)
            {

                cin >> arr[i][j];
            }
        }

        int **dp = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            int *rdp = new int[m];
            for (int j = 0; j < m ; j++)
            {
                rdp[j] = 0;
            }
            dp[i] = rdp;
        }
        for (int i = 0; i < m; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (arr[i][j] >= arr[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = i;
                }
            }
        }

        int *fnl = new int[n + 1];
        minElem(dp, n,m,fnl);

        int y;
        cin >> y;
        while (y--)
        {
            int l, r;
            cin >> l >> r;
            if (fnl[r] <= l)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}