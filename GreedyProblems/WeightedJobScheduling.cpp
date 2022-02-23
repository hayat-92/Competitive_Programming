#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct  Interval
{
    int st;
    int ft;
    int p;
};

bool compare(Interval i, Interval j){
    return i.ft<j.ft;
}

int binarySearch(Interval *v, int index){
    int st=0;
    int ed=index-1;
    while (st <= ed)
    {
        int mid = (st + ed) / 2;
        if (v[mid].ft <= v[index].st)
        {
            if (v[mid + 1].ft <= v[index].st)
                st = mid + 1;
            else
                return mid;
        }
        else
            ed = mid - 1;
    }
    return -1;
}

int fXn(Interval *v, int N){
    int *dp=new int[N];
    dp[0]=v[0].p;
    for(int i=1; i<N; i++){
        int sum=v[i].p;;
        // for(int j=i-1; j>=0; j--){
        //     if(v[i].st>=v[j].ft){
        //         sum+=dp[j];
        //         break;
        //     }
        // }
        
        int In=binarySearch(v, i);
        if(In!=-1){
            sum+=dp[In];
        }
        
        dp[i]=max(dp[i-1], sum);
    }

    int result = dp[N-1];
    delete[] dp;
    return result;

    // return dp[v.size()-1];
}


int main(){
    int N;
    cin>>N;
    // int *st=new int[N];
    // int *ft=new int[N];
    // int *p=new int[N];
    // for(int i=0; i<N; i++){
    //     cin>>st[i]>>ft[i]>>p[i];
    // }
    // vector<Interval> v;
    Interval *v=new Interval[N];

    for(int i=0; i<N; i++){
        Interval In;
        cin>>In.st>>In.ft>>In.p;
        v[i]=(In);
    }

    sort(v, v+N, compare);

    cout<<fXn(v, N)<<endl;
    
    return 0;
}