#include<iostream>
using namespace std;

int main(){
    int m=1000000;
    int *primes=new int[m+1];
    for(int i=0; i<=m; i++){
        primes[i]=0;
    }
    for(int i=2; i*i<=m; i++){
        if(primes[i]==0){
            for(int j=1; j*i<=m;j++){
                primes[j*i]+=1;
            }
        }
    }

    int **arr=new int*[11];
    for(int i=0; i<=10; i++){
        arr[i]=new int[m+1];
    }

    for(int i=0; i<=10; i++){
        arr[i][0]=0;
        arr[i][1]=0;
    }

    for(int i=1; i<=10; i++){
        for(int j=1; j<=m; j++){
            if(primes[j]==i){
                arr[i][j]=arr[i][j-1]+1;
            }else{
                arr[i][j]=arr[i][j-1];
            }
        }
    }

    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        cout<<(arr[n][b]-arr[n][a-1])<<endl;
    }
    return 0;
}