#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int S,D;
        cin>>S>>D;
        int *arr=new int[D];
        int sum=S-1;
        for(int i=D-1; i>=1; i--){
            if(sum==0){
                arr[i]=0;
            }
            if(sum>=9){
                arr[i]=9;
                sum-=9;
            }else{
                arr[i]=sum;
                sum-=sum;
            }
        }
        if(sum>0){
            arr[0]=sum+1;
        }else{
            arr[0]=1;
        }
        
        string str="";
        for(int i=0; i<D; i++){

            str=str+to_string(arr[i]);
        }
        cout<<str<<endl;
    }
    return 0;
}