#include<iostream>
using namespace std;

void fxn(int x, int k){
    cout<<x<<" "<<k<<endl;
}

int main(){
    int i=0;
    int x=0;
    fxn(i++, x+1);
    cout<<i;
    return 0;
}