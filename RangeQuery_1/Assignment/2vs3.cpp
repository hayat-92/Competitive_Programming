#include <iostream>
#include<string>
using namespace std;

void buildTree(char* str, int *tree, int start, int end, int treeNode, int *arr){
    if(start==end){
        if(str[start]=='0'){
            tree[treeNode]=0;
        }else{
            tree[treeNode]=1;
        }
        return;
    }

    int mid=(start+end)/2;
    buildTree(str, tree, start, mid, 2*treeNode, arr);
    buildTree(str, tree, mid+1, end, 2*treeNode+1, arr);
    int ans1=(tree[2*treeNode]*(arr[end-mid]))%3;
    int ans2=tree[2*treeNode+1]%3;
    tree[treeNode]=(ans1+ans2)%3;
}

int query(int *tree, int start, int end, int treeNode,int i, int j, int *arr){
    if(start>j || end<i){
        return 0;
    }

    if(start>=i && end<=j){
        return (tree[treeNode]*(arr[j-end]))%3;
    }

    

    int mid=(start+end)/2;
    int ans1=query(tree, start, mid, 2*treeNode, i, j, arr);
    int ans2=query(tree, mid+1, end, 2*treeNode+1, i, j, arr);
   
    return (ans1+ans2)%3;
}

void update(char *str, int *tree, int start, int end, int treeNode, int index, int *arr){
    if(start==end){
        if(str[start]=='0'){
        str[index]='1';
        tree[treeNode]=1;
        }
        return;
        
    }

    int mid=(start+end)/2;
    if(index<=mid){
        update(str, tree, start, mid, 2*treeNode, index, arr);
    }else{
        update(str, tree, mid+1, end, 2*treeNode+1, index, arr);
    }

    int ans1=(tree[2*treeNode]*(arr[end-mid]))%3;
    int ans2=tree[2*treeNode+1]%3;
    tree[treeNode]=(ans1+ans2)%3;


}
int main()
{
    int N;
    cin>>N;
    char *str=new char[N];
    cin>>str;
    int *tree=new int[4*N];
    int *arr=new int[100001];
    arr[0]=1;
    for(int i=1; i<100001; i++){
        arr[i]=(arr[i-1]*2)%3;
    }
    
    buildTree(str, tree, 0, N-1, 1, arr);

   
    int q;
    cin>>q;
    while(q--){
        int x, i, j;
        cin>>x;
        if(x==0){
            cin>>i>>j;
            cout<<query(tree, 0, N-1, 1, i, j, arr)<<endl;
        }else{
            cin>>i;
            update(str, tree, 0, N-1, 1, i, arr);
        }
    }
    return 0;
}