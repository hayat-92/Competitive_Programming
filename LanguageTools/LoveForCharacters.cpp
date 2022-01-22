#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char, int> m;
    m['a']=0;
    
    m['s']=0;
    m['p']=0;
    for(int i=0; i<s.length();i++){
        if(s[i]=='a' || s[i]=='p' || s[i]=='s'){
            m[s[i]]++;
        }
    }

    cout<<m['a']<<" "<<m['s']<<" "<<m['p'];
    return 0;
}