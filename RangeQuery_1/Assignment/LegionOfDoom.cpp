#include <iostream>
using namespace std;
typedef long long ll;

void update(ll *arr, ll *tree, ll *lazy, ll start, ll end, ll leftR, ll rightR, ll value, ll treeNode){
    if(start>end){
        return;
    }

    if(lazy[treeNode]!=0){
        tree[treeNode]+=(end-start+1)*lazy[treeNode];
        if(start!=end){
            lazy[2*treeNode]+=lazy[treeNode];
            lazy[2*treeNode+1]+=lazy[treeNode];
        }
        lazy[treeNode]=0;
    }

    if(start>rightR || end<leftR){
        return;
    }

    if(start>=leftR && end<=rightR){
        tree[treeNode]+=(end-start+1)*value;
        if(end!=start){
            lazy[2*treeNode]+=value;
            lazy[2*treeNode+1]+=value;
        }

        return;
    }

    ll mid=(start+end)/2;
    update(arr, tree, lazy, start, mid, leftR, rightR, value, 2*treeNode);
    update(arr, tree, lazy, mid+1, end, leftR, rightR, value, 2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}


ll query(ll *tree, ll *lazy, ll start, ll end, ll leftR, ll rightR, ll treeNode){
    if(start>end){
        return 0;
    }

    if(lazy[treeNode]!=0){
        tree[treeNode]+=(end-start+1)*lazy[treeNode];
        if(start!=end){
            lazy[2*treeNode]+=lazy[treeNode];
            lazy[2*treeNode+1]+=lazy[treeNode];
        }
        lazy[treeNode]=0;
    }

    if(start>rightR || end<leftR){
        return 0;
    }

    if(start>=leftR && end<=rightR){
        return tree[treeNode];
    }

    ll mid=(start+end)/2;

    ll ans1=query(tree, lazy, start, mid, leftR, rightR, 2*treeNode);
    ll ans2=query(tree, lazy, mid+1, end, leftR, rightR, 2*treeNode+1);
    return (ans1+ans2);
    

}



int main()
{

    ll t;
    cin>>t;
    while(t--){
        ll N,C;
        cin>>N>>C;

        ll *arr=new ll[N];
        for(ll i=0; i<N; i++){
            arr[i]=0;
        }

        ll *tree=new ll[4*N];
        for(ll i=1; i<4*N; i++){
            tree[i]=0;
        }

        ll *lazy=new ll[4*N];
        for(ll i=0; i<4*N; i++){
            lazy[i]=0;
        }

        while(C--){
            ll type;
            cin>>type;
            if(type==0){
                ll p, q, v;
                cin>>p>>q>>v;
                update(arr, tree, lazy, 0, N-1, p-1, q-1, v, 1);
            }else{
                ll p,q;
                cin>>p>>q;
                cout<<query(tree, lazy, 0, N-1, p-1, q-1, 1)<<endl;
            }
        }
    }

    return 0;
}