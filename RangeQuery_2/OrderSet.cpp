#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define MAX 200001

int query(int x, int *bit)
{
    if (x == 0)
    {
        return 0;
    }

    ll sum = 0;
    for (int i = x; i > 0;)
    {
        sum += bit[i];
        i -= (i & (-i));
    }
    return sum;
}

void update(int x, int *bit, int value)
{

    for (int i = x; i < MAX;)
    {
        bit[i] += value;
        i += (i & (-i));
    }
}

int main()
{

    int Q;
    cin >> Q;
    vector<int> *arr = new vector<int>();
    pair<char, int> *queryPair = new pair<char, int>[Q];
    for (int i = 0; i < Q; i++)
    {
        cin >> queryPair[i].first >> queryPair[i].second;
        if (queryPair[i].first == 'I')
        {
            arr->push_back(queryPair[i].second);
        }
    }

    sort(arr->begin(), arr->end());

    unordered_map<int, int> *m;
    for (int i = 0; i < (arr->size()); i++)
    {
        m->insert({arr->at(i), i+1});
    }

    int *bit = new int[MAX]();

    for (int i = 0; i < Q; i++)
    {
        if (queryPair[i].first == 'I')
        {
            int x = m->at(queryPair[i].second);
            if (x!=0 && query(x, bit) == query(x-1, bit))
            {
                update(x, bit, 1);
            }
        }
        else if (queryPair[i].first == 'D')
        {
            int x = m->at(queryPair[i].second);
            if (x !=0 && query(x, bit) != query(x-1, bit))
            {
                update(x, bit, -1);
            }
        }
        else if (queryPair[i].first == 'K')
        {
            int start = 1;
            int end = arr->size() - 1;
            int mid;
            int k = queryPair[i].second;
            bool flag = false;
            for (int i = 0; i < arr->size(); i++)
            {
                mid = (start + end) / 2;
                if (query(mid, bit) == k && query(mid - 1, bit) != k)
                {
                    flag = true;
                    break;
                }
                else if (query(mid, bit) > k)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            if (flag)
            {
                cout << "valid" << endl;
            }
            else
            {
                cout << arr->at(mid) << endl;
            }
        }
        else
        {
            int x = lower_bound(arr->begin(), arr->end(), queryPair[i].second) - arr->end();
            // cout<<x<<endl;
            cout << query(x, bit) << endl;
        }
    }

    return 0;
}











