#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
struct Interval
{
    int A;
    int H;
    int index;
};

bool Compare(Interval a, Interval b)
{
    if (a.A < b.A)
    {
        return true;
    }
    else if (a.A == b.A)
    {
        return a.H < b.H;
    }
    else
    {
        return false;
    }
}

int query(int H, int *BIT)
{
    int sum = 0;
    for (int i = H; i > 0;)
    {
        sum += BIT[i];
        i -= (i & (-i));
    }
    return sum;
}

void update(int H, int *BIT)
{
    for (int i = H; i < 100001;)
    {
        BIT[i]++;
        i += (i & (-i));
    }
}

int main()
{

    int N;
    cin >> N;
    Interval *arr = new Interval[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].A >> arr[i].H;
        arr[i].index = i;
    }
    sort(arr, arr + N, Compare);

    int *BIT = new int[100001]();

    int *fnl = new int[N];

    for (int i = 0; i < N;)
    {
        // int ans = query(arr[i].H, BIT);
        // fnl[arr[i].index] = ans;
        // update(arr[i].H, BIT);
        // i++;
        int endIndex = i;
        while (endIndex < N && arr[i].A == arr[endIndex].A && arr[i].H == arr[endIndex].H)
        {
            endIndex++;
        }

        for (int j = i; j < endIndex; j++)
        {
            cout<<"Faisal"<<endl;
            fnl[arr[j].index] = query(arr[j].H, BIT);
        }

        for (int j = i; j < endIndex; j++)
        {
            update(arr[j].H, BIT);
        }

        i=endIndex;
    }

    for (int i = 0; i < N; i++)
    {
        cout << fnl[i] << endl;
    }

    return 0;
}