#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string *arr=new string[n-2];
        for(int i=0; i<n-2; i++){
            cin>>arr[i];
        }
        string str="";
        str+=arr[0][0];
        for(int i=1; i<n-2; i++){
            if(arr[i][0]==arr[i-1][1]){
                str+=arr[i][0];
            }else{
                str+=arr[i-1][1];
                str+=arr[i][0];
            }
        }
        str+=arr[n-3][1];
        if(str.length()!=n){
            str+='a';
        }

        cout<<str<<endl;

    }
    return 0;
}