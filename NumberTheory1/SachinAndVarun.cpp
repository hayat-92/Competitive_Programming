#include<iostream>
using namespace std;

typedef long long ll;



class Triplet{
    public:
    ll x;
    ll y;
    ll gcd;
};

Triplet extendedEuclid(int a, int b){
    if(b==0){
        Triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }

    Triplet smallAns=extendedEuclid(b, a%b);
    Triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x - (a/b)*smallAns.y;
    return ans;
}

ll mmInverse(int a, int m){
    ll x=extendedEuclid(a,m).x;
    return (x%m+m)%m;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a, b, d;
        cin>>a>>b>>d;
        ll g=__gcd(a, b);
        if(d%g){
            cout<<0<<endl;
            continue;
        }

        if(d==0){
            cout<<1<<endl;
            continue;
        }
        a/=g;
        b/=g;
        d/=g;

        ll y1=((d%a)*mmInverse(b, a))%a;
        ll firstValue=d/b;

        if(d<y1*b){
            cout<<0<<endl;
            continue;
        }

        ll n=(firstValue-y1)/a;

        ll ans=n+1;
        cout<<ans<<endl;
    }
    return 0;
}