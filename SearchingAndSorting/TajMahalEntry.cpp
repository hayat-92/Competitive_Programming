#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct Interval {
    int lop;
    int Index;
    int counter;
};

bool compare(Interval A1, Interval A2){
    if(A1.lop<A2.lop){
        return true;
    }

    if(A1.lop>A2.lop){
        return false;
    }

    if(A1.counter<=A1.Index && A2.counter<=A2.Index){
        return A1.Index<A2.Index;
    }else if(A1.counter<=A1.Index && A2.counter>A2.Index){
        return true;
    }
    else if(A1.counter>A1.Index && A2.counter<=A2.Index){
        return false;
    }else{
        return false;
    }

}

int main(){
    int n;
    cin>>n;
    ll *arr=new ll[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

     Interval *v=new Interval[n];
    for(int i=0; i<n; i++){
        int lp=arr[i]/n;
        int count=arr[i]%n;
        Interval e;
        e.lop=lp;
        e.counter=count;
        e.Index=i;
        v[i]=e;
    }
    sort(v, v+n, compare);

    cout<<v[0].Index+1<<endl;
    return 0;
}