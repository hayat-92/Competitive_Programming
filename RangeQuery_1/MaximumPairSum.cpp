#include <iostream>
#include <algorithm>
using namespace std;

struct MaxPair
{
    /* data */
    int fmax;
    int smax;
};

void BuildTree(int *arr, MaxPair *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode].fmax = arr[start];
        tree[treeNode].smax = INT_MIN;
        return;
    }

    int mid = (start + end) / 2;
    BuildTree(arr, tree, start, mid, 2 * treeNode);
    BuildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    int fmax = max(tree[2 * treeNode].fmax, tree[2 * treeNode + 1].fmax);
    int smax = min(max(tree[2 * treeNode].fmax, tree[2 * treeNode + 1].smax), max(tree[2 * treeNode].smax, tree[2 * treeNode + 1].fmax));
    tree[treeNode].fmax = fmax;
    tree[treeNode].smax = smax;
}

void update(int *arr, MaxPair *tree, int start, int end, int treeNode, int index, int value)
{
    // cout<<"Fai"<<endl;
    if (start == end)
    {
        arr[index] = value;
        tree[treeNode].fmax = value;
        return;
    }

    int mid = (start + end) / 2;
    if (mid >= index)
    {
        update(arr, tree, start, mid, 2 * treeNode, index, value);
    }
    else
    {
        update(arr, tree, mid + 1, end, 2 * treeNode + 1, index, value);
    }

    int fmax = max(tree[2 * treeNode].fmax, tree[2 * treeNode + 1].fmax);
    int smax = min(max(tree[2 * treeNode].fmax, tree[2 * treeNode + 1].smax), max(tree[2 * treeNode].smax, tree[2 * treeNode + 1].fmax));
    tree[treeNode].fmax = fmax;
    tree[treeNode].smax = smax;
}

MaxPair query(MaxPair *tree, int start, int end, int treeNode, int i, int j)
{
    if (start > j || end < i)
    {
        MaxPair p;
        p.fmax = INT_MIN;
        p.smax = INT_MIN;
        return p;
    }

    if (start >= i && end <= j)
    {
        return tree[treeNode];
    }

    int mid = (start + end) / 2;
    MaxPair ans1 = query(tree, start, mid, 2 * treeNode, i, j);
    MaxPair ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, i, j);
    MaxPair fnl;
    fnl.fmax = max(ans1.fmax, ans2.fmax);
    fnl.smax = min(max(ans1.fmax, ans2.smax), max(ans1.smax, ans2.fmax));
    return fnl;
}
int main()
{
    int N;
    cin >> N;
    int *arr = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    MaxPair *tree = new MaxPair[4 * N];
    BuildTree(arr, tree, 1, N, 1);
    // for (int i = 1; i <= 2 * N; i++)
    // {
    //     cout << tree[i].fmax << " " << tree[i].smax << endl;
    // }
    int Q;
    cin >> Q;
    while (Q--)
    {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if (c == 'Q')
        {
            MaxPair maxNod = query(tree, 1, N, 1, i, j);
            cout << (maxNod.fmax + maxNod.smax) << endl;
        }
        else
        {
            update(arr, tree, 1, N, 1, i, j);
            // for (int i = 1; i <= 2 * N; i++)
            // {
            //     cout << tree[i].fmax << " " << tree[i].smax << endl;
            // }
        }
    }
    // }

    return 0;
}