#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct Interval{
    string name;
    int sum;
    int roll;
};

bool compare(Interval p1, Interval p2)
{
    if(p1.sum>p2.sum)
    {
        return 1;
    }
    else if(p2.sum>p1.sum)
    {
        return 0;
    }
    else if(p2.sum==p1.sum)
    {
        if(p1.roll<p2.roll)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    Interval *pv=new Interval[n];
    map<string, vector<int>> m;
    int roll=1;
    for(int i=0; i<n; i++){
        string s;
        int m1,m2,m3;
        cin>>s;
        cin>>m1>>m2>>m3;
        int sum=(m1+m2+m3);
        Interval en={s, sum, roll};
        pv[i]=en;
        roll++;
        
    }
    sort(pv, pv+n, compare);
    for(int i=0; i<n; i++){
        cout<<i+1<<" "<<pv[i].name<<endl;
    }
    return 0;
}
