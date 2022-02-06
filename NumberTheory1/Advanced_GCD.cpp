#include<iostream>
using namespace std;
#include<string>

int gcd(int a, int b){
    if(b==0){
        return a;
    }

    return gcd(b, a%b);
}


int lg_gcd(int a, string b){
    int num=0;
    for(int i=0; i<b.length(); i++){
        num=(num*10+ (b[i]-48))%a;
    }
    return gcd(num, a);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a; string b;
        cin>>a;
        cin>>b;
        cout<<lg_gcd(a, b)<<endl;

    }
    return 0;
}