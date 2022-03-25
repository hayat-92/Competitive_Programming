#include <iostream>
#include<algorithm>
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

void updateSegmentedTreeLazy(int *tree, int *lazy, int low, int high, int startR, int endR, int currPos, int inc){
    if(low>high){
        return;
    }

    if(lazy[currPos]!=0){
        tree[currPos]+=lazy[currPos];

        if(low!=high){
            lazy[2*currPos]+=lazy[currPos];
            lazy[2*currPos+1]+=lazy[currPos];
        }
        lazy[currPos]=0;
    }

    if(startR>high || endR< low){
        return;
    }

    if(startR>=low && high<=endR){
        tree[currPos]+=inc;
        if(low!=high){
            lazy[2*currPos]+=inc;
            lazy[2*currPos+1]+=inc;
        }
        return;
    }

    //Partial Overlap
    int mid=(low+high)/2;
    updateSegmentedTreeLazy(tree, lazy, low, mid, startR, endR, 2*currPos, inc);
    updateSegmentedTreeLazy(tree, lazy, mid+1, high, startR, endR, 2*currPos+1, inc);
    tree[currPos]=min(tree[2*currPos], tree[2*currPos+1]);

}

int query(int *tree, int *lazy, int low, int high, int startR, int endR, int treeNode){

    if(lazy[treeNode]!=0){
        tree[treeNode]+=lazy[treeNode];

        if(low!=high){
            lazy[2*treeNode]+=lazy[treeNode];
            lazy[2*treeNode+1]+=lazy[treeNode];
        }
        lazy[treeNode]=0;
    }
    if(startR>high || endR<low){
        return INT_MAX;
    }

    if(low>=startR && high<=endR){
        return tree[treeNode];
    }

    int mid=(low+high)/2;
    int ans1=query(tree, lazy, low, mid, startR, endR, 2*treeNode);
    int ans2=query(tree, lazy, mid+1, high, startR, endR, 2*treeNode+1);
    return min(ans1, ans2);

}


int main()
{

    return 0;
}