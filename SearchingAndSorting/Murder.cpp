#include <iostream>
using namespace std;

typedef long long ll;

ll mergeSort(ll *arr, int n, int st, int en, ll *output)
{
    if(st>en){
        return 0;
    }
    if(st==en){
        output[0]=arr[st];
        return 0;
    }
    int mid = (st + en) / 2;

    ll *A1 = new ll[n - n / 2];
    ll *A2 = new ll[n / 2];

    ll Lcount = mergeSort(arr, n - n / 2, st, mid, A1);
    ll Rcount = mergeSort(arr, n / 2, mid + 1, en, A2);

    int i = 0, j = 0, k = 0;
    ll count = 0;
    for (; i < (n - n / 2) && j < n / 2;)
    {
        if (A1[i] < A2[j])
        {
            output[k++] = A1[i];
            count += (n / 2 - j) * A1[i];
            i++;
        }
        else
        {
            output[k++] = A2[j];
            j++;
        }
    }

    while (i < (n - n / 2))
    {
        output[k++] = A1[i++];
    }

    while (j < n / 2)
    {
        output[k++] = A2[j++];
    }

    ll totalCount = count + Lcount + Rcount;
    return totalCount;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        ll *arr = new ll[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        ll *output = new ll[N];

        cout << mergeSort(arr, N, 0, N - 1, output)<<endl;
    }

    return 0;
}