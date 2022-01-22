#include<iostream>
using namespace std;

int checkPrime(int n){
    bool *arr=new bool[n+1];
    for(int i=0; i<=n; i++){
        arr[i]=true;
    }

    arr[0]=false;
    arr[1]=false;
    for(int i=2; i*i<=n; i++){
        if(arr[i]){
            for(int j=i; j*i<=n;j++){
                arr[j*i]=false;
            }
        }
    }

    int count=0;
    for(int i=0; i<=n; i++){
        if(arr[i]){
            count++;
        }
    }

    return count;


}

int main(){
    int n;
    cin>>n;
    cout<<checkPrime(n)<<endl;
    return 0;
}