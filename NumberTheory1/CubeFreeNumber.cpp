#include<iostream>
using namespace std;
// #define m 1000000;

int main(){
    int m=1000000;
    int *sieve=new int[m+1];
    for(int i=0; i<=m; i++){
        sieve[i]=0;
    }

    for(int i=2; i<=100; i++){
        int p=i*i*i;
        while(p<=m){
            sieve[p]=-1;
            p+=p;
        }
    }

    int *arr=new int[m+1];
    int count=0;
    for(int i=0; i<=m; i++){
        if(sieve[i]==0){
            arr[i]=count;
            count++;
        }else{
            arr[i]=-1;
        }
    }


    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(arr[n]==-1){
            cout<<"Not Cube Free"<<endl;
        }else{
            cout<<arr[n]<<endl;
        }
    }
}