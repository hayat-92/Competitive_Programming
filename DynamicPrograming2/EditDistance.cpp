#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int editDistance(string s1, string s2,int m, int n, int **dp){
    if(m==0 && n!=0){
        return n;
    }

    if(n==0 && m!=0){
        return m;
    }

    if(m==0 && n==0){
        return 0;
    }

    if(dp[m][n]>-1){
        return dp[m][n];
    }

    int val;

    if(s1[0]==s2[0]){
        val=editDistance(s1.substr(1), s2.substr(1), m-1, n-1, dp);
    }else{
        val=1+min(editDistance(s1.substr(1), s2.substr(1), m-1, n-1, dp), min(editDistance(s1, s2.substr(1), m, n-1, dp), editDistance(s1.substr(1), s2, m-1, n, dp)));
    }

    dp[m][n]=val;
    return val;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int **dp=new int*[s1.length()+1];
        for(int i=0; i<s1.length()+1; i++){
            dp[i]=new int[s2.length()+1];
            for(int j=0; j<s2.length()+1; j++){
                dp[i][j]=-1;
            }
        }
        cout<<editDistance(s1, s2,s1.length(), s2.length(), dp)<<endl;
    }
    return 0;
}