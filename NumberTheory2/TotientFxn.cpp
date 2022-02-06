#include <iostream>
using namespace std;

#define m 1000000007;

typedef long long ll;

ll fxn(ll n)
{
    ll *arr = new ll[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        arr[i] = i;
    }
    
    for (ll i = 2; i <= n; i++)
    {
        if (arr[i]==i)
        {
            arr[i] = i - 1;
            for (ll j = 2*i; j <= n; j+=i)
            {
                arr[j ] = (arr[j] * (i - 1)) / i;
            }
        }
    }

    return arr[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << fxn(n) << endl;
    }
    return 0;
}