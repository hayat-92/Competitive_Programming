#include<iostream>
using namespace std;

int modExp(int a, int b, int c){
    if(a==0){
        cout<<"fai"<<endl;
        return 0;
    }

    if(b==0){
        return 1;
    }

    long ans;
    if(b%2==0){ 
        //b is even
        long smallAns=modExp(a, b/2, c);
        ans=(smallAns*smallAns)%c;
    }else{
        long smallAns=modExp(a, b-1, c);
        ans=a%c;
        ans=(ans*smallAns)%c;
    }


    return int((ans+c)%c);
}

int fxn(int N, int P){
    if(N>=P){
        return 0;
    }
    int prod=-1;
    for(int i=N+1; i<P; i++){
        int val=modExp(i, P-2, P)%P;
        if(val==0){
            break;
        }else{
        prod=(prod*val)%P;
        }
    }
    return (prod%P +P)%P;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, P;
        cin>>N>>P;
        cout<<fxn(N, P)<<endl;
    }
    return 0;
}