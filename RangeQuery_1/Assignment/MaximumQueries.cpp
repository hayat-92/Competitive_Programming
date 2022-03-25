#include <iostream>
#include<algorithm>
using namespace std;
void buildTree(int *arr, int *tree, int start, int end, int treeNode){
    if(start>end){
        return;
    }
    if(start==end){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    tree[treeNode]=max(tree[2*treeNode], tree[2*treeNode+1]);
}

int fXn(int *tree, int start, int end, int treeNode, int i, int j){
    if(start>j || end< i){
        return INT_MIN;
    }

    if(start>=i && end<=j){
        return tree[treeNode];
    }

    int mid=(start+end)/2;
    int ans1=fXn(tree, start, mid, 2*treeNode, i, j);
    int ans2=fXn(tree, mid+1, end, 2*treeNode+1, i, j);
    return max(ans1, ans2);
}
int main()
{
    int N;
    cin>>N;
    int *arr=new int[N];
    for(int i=0; i<N;i++){
        cin>>arr[i];
    }

    int *tree=new int[4*N];
    buildTree(arr, tree, 0, N-1, 1);
    int q;
    cin>>q;
    while(q--){
        int i, j;
        cin>>i>>j;
        cout<<fXn(tree, 0, N-1, 1, i, j )<<endl;
    }

    return 0;
}