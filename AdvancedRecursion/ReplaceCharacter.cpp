#include<iostream>
#include<string>
using namespace std;

string charReplace(string str, char c1, char c2){
    if(str.length()==0){
        return "";
    }

    string nstr=charReplace(str.substr(1, (str.length()-1)), c1, c2);
    string fstr="";
    if(str[0]==c1){
        fstr=c2+nstr;
    }else{
        fstr=str[0]+nstr;
    }

    return fstr;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        char c1,c2;
        cin>>c1>>c2;
        cout<<charReplace(str, c1, c2)<<endl;

    }
    return 0;
}