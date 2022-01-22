#include<iostream>
#include<cmath>
using namespace std;

int prodNatural(int n){
    long prod=1;
    int m=pow(10,9)+7;
    for(int i=1; i<n+1; i++){
        prod=prod*i;
    }

    int total=(int)(prod%m);
    return total;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<prodNatural(n)<<endl;
    }
    return 0;
}