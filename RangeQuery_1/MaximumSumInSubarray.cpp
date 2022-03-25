#include <iostream>
#include<algorithm>
using namespace std;
struct SubarrayInterval
{
    /* data */
    int MaxSum;
    int Sum;
    int BestSufxSum;
    int BestPrefSum;
};

void BuildTree(int *arr, SubarrayInterval *tree, int start, int end, int treeNode){
    if(start==end){
        SubarrayInterval e;
        e.Sum=arr[start];
        e.MaxSum=arr[start];
        e.BestPrefSum=arr[start];
        e.BestSufxSum=arr[start];
        tree[treeNode]=e;
        return;
    }

    int mid=(start+end)/2;
    BuildTree(arr, tree, start, mid, 2*treeNode);
    BuildTree(arr, tree, mid+1, end, 2*treeNode+1);


    SubarrayInterval LSubArray=tree[2*treeNode];
    SubarrayInterval RSubArray=tree[2*treeNode+1];

    int maxsum=max(LSubArray.MaxSum, RSubArray.MaxSum);
    int prefSum=LSubArray.Sum+RSubArray.BestPrefSum;
    int sufxsum=RSubArray.Sum+LSubArray.BestSufxSum;
    int BWSum=LSubArray.BestSufxSum+RSubArray.BestPrefSum;

    tree[treeNode].MaxSum=max(max(maxsum, prefSum), max(sufxsum, BWSum));
    tree[treeNode].BestPrefSum=max(LSubArray.BestPrefSum, prefSum);
    tree[treeNode].BestSufxSum=max(RSubArray.BestSufxSum, sufxsum);
    tree[treeNode].Sum=LSubArray.Sum+RSubArray.Sum;

}

SubarrayInterval query(SubarrayInterval *tree, int start, int end, int treeNode, int i, int j){
    if(start>j || end<i){
        SubarrayInterval e;
        e.Sum=-100000;
        e.MaxSum=-100000;
        e.BestPrefSum=-100000;
        e.BestSufxSum=-100000;
        return e;
        
    }

    if(start>=i && end<=j){
        return tree[treeNode];
    }

    int mid=(start+end)/2;
    SubarrayInterval LSubArray =query(tree, start, mid, 2*treeNode, i, j);
    SubarrayInterval RSubArray=query(tree, mid+1, end, 2*treeNode+1, i, j);
    int maxsum=max(LSubArray.MaxSum, RSubArray.MaxSum);
    int prefSum=LSubArray.Sum+RSubArray.BestPrefSum;
    int sufxsum=RSubArray.Sum+LSubArray.BestSufxSum;
    int BWSum=LSubArray.BestSufxSum+RSubArray.BestPrefSum;

    SubarrayInterval fnl;
    fnl.MaxSum=max(max(maxsum, prefSum), max(sufxsum, BWSum));
    fnl.BestPrefSum=max(LSubArray.BestPrefSum, prefSum);
    fnl.BestSufxSum=max(RSubArray.BestSufxSum, sufxsum);
    fnl.Sum=LSubArray.Sum+RSubArray.Sum;

    return fnl;
}

int main()
{

    int N;
    cin>>N;
    int *arr=new int[N+1];
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }



    SubarrayInterval *tree=new SubarrayInterval[4*N];
    BuildTree(arr, tree, 1, N, 1);
    // for(int i=1; i<=2*N; i++){
    //     cout<<tree[i].MaxSum<<" "<<tree[i].Sum<<" "<<tree[i].BestPrefSum<<" "<<tree[i].BestSufxSum<<endl;
    // }
    int M;
    cin>>M;
    while(M--){
        int x, y;
        cin>>x>>y;
        cout<<query(tree,1, N, 1, x, y).MaxSum<<endl;
    }

    return 0;
}