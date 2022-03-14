#include <iostream>
#include <algorithm>
using namespace std;
class event
{
public:
    int first, second, index;
};

bool compare(event a, event b)
{
    return a.second < b.second;
}

void update(int index, int value, int n, int *bit)
{
    for (; index <= n; index += (index & (-index)))
    {
        bit[index] += value;
    }
}

int value(int index, int *bit)
{
    int count = 0;
    for (; index > 0; index -= (index & (-index)))
    {
        count += bit[index];
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    event *query = new event[q];
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first >> query[i].second;
        query[i].index = i;
    }

    sort(query, query + q, compare);

    int *bit = new int[n + 1];
    int *ans = new int[q];

    for(int i=0;i<=n; i++){
        bit[i]=0;
    }

    int total = 0;
    int k = 0;
    int *last = new int[1000001];

    for (int i = 0; i <= 1000000; i++)
    {
        last[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (last[arr[i]] != -1)
        {
            update(last[arr[i]], -1, n, bit);
        }
        else
        {
            total++;
        }

        update(i, 1, n, bit);
        last[arr[i]] = i;
        while (k < q && query[k].second == i)
        {
            ans[query[k].index] = total - value(query[k].first - 1, bit);
            k++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}