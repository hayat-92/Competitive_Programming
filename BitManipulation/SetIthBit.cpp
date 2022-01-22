#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, i;
        cin>>n>>i;
        n=n|(1<<i);
        cout<<n<<endl;
    }
    return 0;
}