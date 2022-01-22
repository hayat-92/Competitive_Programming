#include<iostream>
#include<string>
using namespace std;

void subSeq(string str, string output){
    if(str.empty()){
        cout<<output<<endl;
        return;
    }

    subSeq(str.substr(1), output);
    subSeq(str.substr(1), output+str[0]);
}

int main(){
    string s;
    cin>>s;
    subSeq(s, "");
    return 0;
}
