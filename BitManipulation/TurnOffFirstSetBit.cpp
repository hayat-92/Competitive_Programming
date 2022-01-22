#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n=(n&(~n+1))^n;
        // n
        cout<<n<<endl;
    }
    return 0;
}