#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll *arr=new ll[n+1];
        arr[0]=0;
        for(ll i=1; i<=n; i++){
            cin>>arr[i];
        }

        sort(arr,arr+n+1);
        ll absum=0;
        ll sum=arr[1];
        for(ll i=2; i<=k; i++){
            absum+=((i-1)*arr[i]-sum);
            sum+=arr[i];

        }
     
        ll j=1;
        ll cost=absum;
        for(ll i=k+1; i<=n; i++){
            sum-=arr[j++];
            absum=absum-2*sum+(k-1)*(arr[i-k])+ (k-1)*(arr[i]);
            cost=min(cost, absum);
            sum+=arr[i];

        }

        cout<<cost<<endl;

    }
    return 0;
}