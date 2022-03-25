#include <iostream>
#include <algorithm>
using namespace std;

void BuildTree(int *arr, int *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    BuildTree(arr, tree, start, mid, 2 * treeNode);
    BuildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = min(tree[2 * treeNode] , tree[2 * treeNode + 1]);
}

void update(int *arr, int *tree, int start, int end, int treeNode, int index, int value)
{
    if(start>end){
        return;
    }
    if (start == end)
    {
        arr[index] = value;
        tree[treeNode] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (index > mid)
    {
        update(arr, tree, mid + 1, end, 2 * treeNode + 1, index, value);
    }
    else
    {
        update(arr, tree, start, mid, 2 * treeNode, index, value);
    }

    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

int query(int *tree, int start, int end, int treeNode, int i, int j){
    if(start>j || end<i){
        return INT_MAX;
    }

    if(start>=i && end<=j){
        return tree[treeNode];
    }

    int mid=(start+end)/2;

    int ans1=query(tree, start, mid, 2*treeNode, i, j);
    int ans2=query(tree, mid+1, end, 2*treeNode+1, i, j);
    return min(ans1, ans2);
}
int main()
{

    int N, Q;
    cin >> N >> Q;
    int *arr = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int *tree = new int[4 * N];
    BuildTree(arr, tree, 1, N, 1);

    while (Q--)
    {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if(c=='q'){
        cout<<query(tree, 1, N,1, i, j)<<endl;
        }else{
        update(arr, tree, 1, N, 1, i, j);

        }
    }

    return 0;
}