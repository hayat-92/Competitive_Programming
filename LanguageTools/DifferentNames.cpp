#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    vector<int> v;
    map<string, int> m;
    int i=0, j=0;
    for(; i<s.length(); i++){
        if(s[i]==' '){
            m[s.substr(j,i-j)]++;
            j=i+1;
        }
    }
    m[s.substr(j,i-j)]++;

    int count=0;
    map<string, int>:: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        if((*it).second>1){
            count++;
            cout<<(*it).first<<" "<<(*it).second<<endl;
        } 
    }

    if(count==0){
        cout<<-1<<endl;
    }

    // cout<<s;
    return 0;
}