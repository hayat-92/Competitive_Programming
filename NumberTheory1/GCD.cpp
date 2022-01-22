#include<iostream>
using namespace std;

//Answer Step applying Euclid's Algorithm

int gcd(int x, int y){
    if(y==0){
        return x;
    }
    if(x>y){
        return gcd(y, x%y);
    }else{
        return gcd(x, y%x);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        cout<<gcd(x, y)<<endl;
    }
    return 0;
}