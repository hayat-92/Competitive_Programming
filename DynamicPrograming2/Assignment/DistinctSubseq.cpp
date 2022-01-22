#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

ll m = pow(10, 9) + 7;

void fXn(string str, int n, ll &count, string s , map<string, int> *mp, int *dp)
{
    if (n == 0)
    {
        
        if((*mp)[s]==0){
            count=(count+1)%m;
            (*mp)[s]+=1;
        }
        
        return;
    }
    if(dp[n]>-1){
        
        count=dp[n];
        return;
    }
    fXn(str.substr(1, str.length() - 1), n - 1, count, s + str[0], mp, dp);
    fXn(str.substr(1, str.length() - 1), n - 1, count, s, mp, dp);
    dp[n]=count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        ll count = 0;
        map<string, int> mp;
        int *dp=new int[str.length()+1];
        for(int i=0; i<str.length()+1; i++){
            dp[i]=-1;
        }
        fXn(str, str.length(), count, "", &mp, dp);
        cout <<count << endl;
    }
    return 0;
}