#include<iostream>
using namespace std;

bool checkPrime(int n){
    int count=0;
    for(int j=1; j*j<=n; j++){
        if(n%j==0){
            if((j*j)==n){
                count+=1;
            }else{
                count+=2;
            }
        }
    }
    if(count==2){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=1; i<=n; i++){
        if(checkPrime(i)){
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}