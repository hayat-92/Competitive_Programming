#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int div=1;
    for(int i=2; i<=10; i++){
        if(n%i==0){
            div=i;
        }
    }
    cout<<div<<endl;
    return 0;
}