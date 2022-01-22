#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll NOfStair(int n, ll *arr)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    if (arr[n] > 0)
    {
        // cout<<"faisal"<<endl;
        return arr[n];
    }

    ll m = pow(10, 9) + 7;

    ll output = NOfStair(n - 1, arr) + NOfStair(n - 2, arr) + NOfStair(n - 3, arr);
    arr[n] = output;
    return output;
}

ll NofStairItr(int n){
    ll *output=new ll[n+1];
    output[0]=1;
    output[1]=1;
    output[2]=2;
    for(int i=3; i<n+1; i++){
        ll fnl=output[i-1]+output[i-2]+output[i-3];
        output[i]=fnl;
    }

    return output[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            arr[i] = 0;
        }
        ll out=NofStairItr(n);
        // ll out = arr[n];
        ll m = pow(10, 9) + 7;

        cout << (out%m) << endl;

        delete[] arr;
    }

    return 0;
}