#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;


struct Interval{
    ll val;
    ll weigh;
    double avg;
};

bool compare(Interval i1, Interval i2){
    return i1.avg > i2.avg;
}

double fXn(vector<Interval> v, int W){
    double maxVal=0;
    for(int i=0; i<v.size(); i++){
        if(W==0){
            break;
        }
        if(W>=v[i].weigh){
            maxVal+=(double)v[i].val;
            W-=v[i].weigh;
        }else{
            maxVal+=(v[i].avg*(double)W);
            W=0;
            break;
        }
    }

    return maxVal;
}

int main(){
    ll N, W;
    cin>>N>>W;
    ll *value=new ll[N];
    ll *weight=new ll[N];
    for(ll i=0; i<N; i++){
        cin>>value[i]>>weight[i];
    }
    vector<Interval> v;
    for(int i=0; i<N; i++){
        Interval In;
        In.val=value[i];
        In.weigh=weight[i];
        In.avg=((double)value[i])/(weight[i]);
        v.push_back(In);
    }

    sort(v.begin(), v.end(), compare);
    cout<<fixed << setprecision(6)<<fXn(v, W)<<endl;
    

    return 0;
}