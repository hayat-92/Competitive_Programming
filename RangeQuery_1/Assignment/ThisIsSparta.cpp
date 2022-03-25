#include <iostream>
using namespace std;
struct IsSparta
{
    /* data */
    int maxStrength;
    int minCowardice;
    int index;
};

void buildTree(int *strength, int *cowardce, IsSparta *tree, int start, int end, int treeNode){
    if(start==end){
        tree[treeNode].index=start;
        tree[treeNode].maxStrength=strength[start];
        tree[treeNode].minCowardice=cowardce[start];
        return;
    }

    int mid=(start+end)/2;

    buildTree(strength, cowardce, tree, start, mid, 2*treeNode);
    buildTree(strength, cowardce, tree, mid+1, end, 2*treeNode+1);
    IsSparta ans1=tree[2*treeNode];
    IsSparta ans2=tree[2*treeNode+1];
    if(ans1.maxStrength>ans2.maxStrength){
        tree[treeNode]=ans1;
    }else if(ans2.maxStrength>ans1.maxStrength){
        tree[treeNode]=ans2;
    }else if(ans1.minCowardice<ans2.minCowardice){
        tree[treeNode]=ans1;
    }else if(ans1.minCowardice>ans2.minCowardice){
        tree[treeNode]=ans2;
    }else if(ans1.index<ans2.index){
        tree[treeNode]=ans1;
    }else{
        tree[treeNode]=ans2;
    }
}

IsSparta query(IsSparta *tree, int start, int end, int treeNode, int i, int j){
    if(start>j || end<i){
        IsSparta s;
        s.index=-1;
        s.maxStrength=INT_MIN;
        s.minCowardice=INT_MAX;
        return s;
    }

    if(start>=i && end<=j){
        return tree[treeNode];
    }

    int mid=(start+end)/2;
    IsSparta ans1=query(tree, start, mid, 2*treeNode, i, j);
    IsSparta ans2=query(tree, mid+1, end, 2*treeNode+1, i, j);

    if(ans1.maxStrength>ans2.maxStrength){
        return ans1;
    }else if(ans2.maxStrength>ans1.maxStrength){
         return ans2;
    }else if(ans1.minCowardice<ans2.minCowardice){
        return ans1;
    }else if(ans1.minCowardice>ans2.minCowardice){
        return ans2;
    }else if(ans1.index<ans2.index){
        return ans1;
    }else{
        return ans2;
    }
}

int main()
{
    int N;
    cin>>N;
    int *strength=new int[N+1];
    for(int i=1; i<=N; i++){
        cin>>strength[i];
    }
    int *cowardice=new int[N+1];
    for(int i=1; i<=N; i++){
        cin>>cowardice[i];
    }

    IsSparta *tree=new IsSparta[4*N];
    buildTree(strength, cowardice, tree, 1, N, 1);

    int q;
    cin>>q;
    while(q--){
        int i, j;
        cin>>i>>j;
        cout<<query(tree, 1, N, 1, i, j).index<<endl;
    }

    

    return 0;
}