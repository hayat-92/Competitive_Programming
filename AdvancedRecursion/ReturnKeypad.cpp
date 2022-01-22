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

int keypad(int num, string output[]){
    if(num==0){
        output[0]="";
        return 1;
    }

    int rem=num%10;

    string str=keyvalue(rem);
    int c=keypad(num/10, output);
    string *narr=new string[c];
    for(int i=0; i<c; i++){
        narr[i]=output[i];
    }

    int k=0;

    for(int i=0; i<c; i++){
        for(int j=0; j<str.length(); j++){
            output[k++]=narr[i]+str[j];
        }
    }

    return str.length()*c;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string *output=new string[1000000];
        int size=keypad(n, output);
        for(int i=0; i<size; i++){
            cout<<output[i]<<endl;;
        }

        cout<<endl;
    }
    return 0;
}