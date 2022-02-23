#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;


struct llerval{
    ll st;
    ll et;
};

bool compare(llerval i1, llerval i2){
    return i1.et < i2.et;
}

ll fXn(vector<llerval> v){
    ll count=1;
    llerval ptr=v[0];
    for(ll i=1; i<v.size(); i++){
        if(v[i].st>=ptr.et){
            count++;
            ptr=v[i];
        }
    }

    return count;
}

int main(){
    ll N;
    cin>>N;
    ll *stArr=new ll[N];
    ll *enArr=new ll[N];
    for(ll i=0; i<N; i++){
        cin>>stArr[i]>>enArr[i];
    }
    vector<llerval> v;
    for(ll i=0; i<N; i++){
        llerval In;
        In.st=stArr[i];
        In.et=enArr[i];
        v.push_back(In);
    }

    sort(v.begin(), v.end(), compare);
    cout<<fXn(v)<<endl;

    return 0;
}