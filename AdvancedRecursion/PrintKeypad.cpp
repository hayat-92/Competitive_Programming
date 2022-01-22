#include<iostream>
#include<string>
using namespace std;


string keyvalue(int num){
    if(num==2){
        return "abc";
    }else if(num==3){
        return "def";
    }else if(num==4){
        return "ghi";
    }else if(num==5){
        return "jkl";
    }else if(num==5){
        return "mno";
    }else if(num==7){
        return "pqrs";
    }else if(num==8){
        return "tuv";
    }else if(num==9){
        return "wxyz";
    }else{
        return "";
    }
}

void keypad(int num, string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }

    string rem=keyvalue(num%10);
    for(int i=0; i<rem.length(); i++){
        keypad(num/10, rem[i]+output);
    }


}

void printKeypad(int num){
    keypad(num, "");
}

int main(){
    string s;
    cin>>s;
    printKeypad(23);
    return 0;
}