#include<iostream>
using namespace std;

class Triplet{
    public:
    int x;
    int y;
    int gcd;
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

int mmInverse(int a, int m){
    Triplet ans=extendedEuclid(a,m);
    return ans.x;
}

int main(){
    // int a=15;
    // int b=10;
    // Triplet ans=extendedEuclid(a,b);
    // cout<<ans.gcd<<endl;
    // cout<<ans.x<<endl;
    // cout<<ans.y<<endl;

    int a=5;
    int m=12;
    int ans=mmInverse(a, m);
    cout<<"Multiplicative Modulo Inverse Is "<<ans<<endl;
    return 0;
}