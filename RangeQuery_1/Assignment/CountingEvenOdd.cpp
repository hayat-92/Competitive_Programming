#include <iostream>
using namespace std;

struct EvenOdd
{
    /* data */
    int even;
    int odd;
};

void buildTree(int *arr, EvenOdd *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        if (arr[start] % 2 == 0)
        {
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;
        }
        else
        {
            tree[treeNode].even = 0;
            tree[treeNode].odd = 1;
        }
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode].even = tree[2 * treeNode].even + tree[2 * treeNode + 1].even;
    tree[treeNode].odd = tree[2 * treeNode].odd + tree[2 * treeNode + 1].odd;
}

EvenOdd query(EvenOdd *tree, int start, int end, int treeNode, int i, int j)
{
    if (start > j || end < i)
    {
        EvenOdd e;
        e.even = 0;
        e.odd = 0;
        return e;
    }

    if (start >= i && end <= j)
    {
        return tree[treeNode];
    }

    int mid = (start + end) / 2;
    EvenOdd ans1 = query(tree, start, mid, 2 * treeNode, i, j);
    EvenOdd ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, i, j);
    EvenOdd newAns;
    newAns.even = ans1.even + ans2.even;
    newAns.odd = ans1.odd + ans2.odd;
    return newAns;
}

void update(int *arr, EvenOdd *tree, int start, int end, int treeNode, int index, int value)
{
    if (start > end)
    {
        return;
    }

    if (start == end)
    {
        arr[index] = value;
        if (value % 2 == 0)
        {
            tree[treeNode].even = 1;
            tree[treeNode].odd = 0;
        }
        else
        {
            tree[treeNode].odd = 1;
            tree[treeNode].even = 0;
        }
        return;
    }

    int mid = (start + end) / 2;

    if (index <= mid)
    {
        update(arr, tree, start, mid, 2 * treeNode, index, value);
    }
    else
    {
        update(arr, tree, mid + 1, end, 2 * treeNode + 1, index, value);
    }

    tree[treeNode].even = tree[2 * treeNode].even + tree[2 * treeNode + 1].even;
    tree[treeNode].odd = tree[2 * treeNode].odd + tree[2 * treeNode + 1].odd;
}
int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    EvenOdd *tree = new EvenOdd[4 * N];

    buildTree(arr, tree, 0, N - 1, 1);

    int q;
    cin >> q;
    while (q--)
    {
        int f, x, y;
        cin >> f >> x >> y;
        if (f == 0)
        {
            update(arr, tree, 0, N - 1, 1, x-1, y);
        }
        else if (f == 1)
        {
            cout << query(tree, 0, N - 1, 1, x-1, y-1).even << endl;
        }
        else
        {
            cout << query(tree, 0, N - 1, 1, x-1, y-1).odd << endl;
        }
    }

    return 0;
}