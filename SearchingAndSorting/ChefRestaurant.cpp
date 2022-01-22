#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

struct Interval
{
    int st;
    int en;
};

void ChefCheck(vector<pair<int, int>> v, int n, int val)
{
    auto In1 = std::lower_bound(v.begin(), v.end(), make_pair(val, -1),
                                [](auto lhs, auto rhs)
                                { return lhs.first < rhs.first; });
    int In = In1 - v.begin();
    if (In == v.size())
    {
        cout << -1 << endl;
        return;
    }

    pair<int, int> elem = v[In];

    if (In == 0)
    {
        int ans = v[0].first - val;
        cout << ans << endl;
        return;
    }
    if ((elem.first) == val)
    {
        cout << 0 << endl;
        return;
    }

    pair<int, int> elem2 = v[In - 1];
    if (val > (elem2.first) && val < (elem2.second))
    {
        cout << 0 << endl;
        return;
    }

    if (val >= elem2.second && val < elem.first)
    {
        cout << elem.first - val << endl;
        return;
    }
}

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++)
        {
            int st, en;
            pair<int, int> e;
            cin >> (st) >> (en);
            e = make_pair(st, en);
            v.push_back(e);
        }
        int M;
        cin >> M;
        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < M; i++)
        {
            int x;
            cin >> x;
            ChefCheck(v, N, x);
        }
    }
    return 0;
}