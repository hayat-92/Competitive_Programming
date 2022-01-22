#include<iostream>
using namespace std;
#include<algorithm>
typedef long long ll;

long long merge(ll st, ll en, ll n, ll &ans){
   
   
    if(st>en){
        return ans;
    }

    ll mid=(st+en)/2;
    ll sum=n;
    ll kcount=0;
    while(sum>0){
       
        kcount=kcount+min(mid, sum);
        sum-=mid;
        sum-=(sum/10);
    }

    ll ksum=2*kcount;
    ll num;
    if(ksum<n){
        num=merge(mid+1, en, n, ans);
        return num;
    }else{
        ans=mid;
        num=merge(st, mid-1, n, ans);
        return num;
    }

    

    // return min(num,mid);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        cout<<merge(1, n, n, n)<<endl;

    }

    // ll sum=272;
    // int mid=11;
    // int kcount=0;

    // while(sum>=0){
    //     // cout<<"Hassan"<<endl;
    //     // cout<<mid<<endl;
    //     // cout<<st<<" "<<en<<endl;
    //     if(sum<mid){
    //         break;
    //     }
    //     kcount++;
    //     sum-=mid;
    //     sum-=(sum/10);
    // }

    // cout<<sum<<" "<<kcount<<" "<<(kcount*mid+sum)<<endl;
    return 0;
}