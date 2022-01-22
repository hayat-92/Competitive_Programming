#include <iostream>
using namespace std;

typedef long long ll;

#define m 1000000007

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int seqCount(int *arr, int n)
{
    ll **dp = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        ll *arr = new ll[1001];
        for (int j = 0; j < 1001; j++)
        {
            arr[j] = 0;
        }
        dp[i] = arr;
    }

    dp[0][arr[0]] = 1;
    ll sum = dp[0][1];

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                for (int k = 1; k <= 100; k++)
                {
                    int ng = gcd(k, arr[i]);
                    dp[i][ng] += dp[j][k];
                }
            }
        }

        dp[i][arr[i]]++;
        sum = (sum + dp[i][1]) % m;
    }

    cout<<sum<<endl;
	for (int i = 0; i < n; i++)
	{
		delete[] dp[i];
	}
	delete[]dp;
	// delete[]arr;
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

        delete [] arr;
    }
    return 0;
}