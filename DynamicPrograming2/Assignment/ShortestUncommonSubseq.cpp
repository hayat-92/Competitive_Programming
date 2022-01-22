#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int fXn(string s, string v, int **dp){
    if(s.length()==0){
        return 10000007;
    }

    if(v.length()<=0){
        return 1;
    }

    if(dp[s.length()][v.length()]>-1){
        return dp[s.length()][v.length()];
    }

    int i=0;
    for(; i<v.length();i++){
        if(v[i]==s[0]){
            break;
        }
    }

    if(i==v.length()){
        return 1;
    }

    
    int t2=fXn(s.substr(1), v, dp);
    int t1=1+fXn(s.substr(1), v.substr(i+1), dp);
    int fnl=min(t1, t2);
    dp[s.length()][v.size()]=fnl;
    return fnl;
}

int main(){
    string s, v;
    cin>>s;
    cin>>v;
    int **dp=new int*[s.length()+1];
    for(int i=0; i<s.length()+1; i++){
        dp[i]=new int[v.length()+1];
        for(int j=0; j<v.length()+1; j++){
            dp[i][j]=-1;
        }
    }
    cout<<fXn(s, v, dp)<<endl;
    return 0;
}