#include <iostream>
using namespace std;
typedef long long ll;
// #define m 100000;

ll *fxn()
{
    int m = 100001;
    ll *arr = new ll[m];
    for (ll i = 0; i <= m; i++)
    {
        arr[i] = i;
    }

    for (ll i = 2; i <= m; i++)
    {
        if (arr[i] == i)
        {
            arr[i] = i - 1;
            for (ll j = 2 * i; j <= m; j += i)
            {
                arr[j] = (arr[j] * (i - 1)) / i;
            }
        }
    }

    ll *ans = new ll[m];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j += i)
        {
            ans[j] += arr[i] * i;
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    ll * ans=fxn();
    while (t--)
    {
        int n;
        cin >> n;
        ll fnl = ans[n] + 1;
        fnl = (n * fnl) / 2;
        cout << fnl << endl;
    }

    return 0;
}