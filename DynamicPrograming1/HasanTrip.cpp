#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
#include <iomanip>
using namespace std;

struct Interval
{
    int x;
    int y;
    int h;
};

double distance(Interval a, Interval b){
	double ans = 0;
	long long X = (long long)pow(a.x-b.x, 2);
	long long Y = (long long)pow(a.y-b.y, 2);
	
	ans = (double)sqrt(X+Y);
	return ans;
}

double maxHap(vector<Interval> v){

    double *dp=new double[v.size()];
    dp[0]=v[0].h;
    for(int i=1; i<v.size(); i++){
        double temp=INT_MIN;
        for(int j=0; j<i; j++){
            double curMax=dp[j]+v[i].h-distance(v[i],v[j]);
            temp=max(temp, curMax);
        }
        dp[i]=temp;
    }

    double fnl=dp[v.size()-1];
    delete [] dp;
    return fnl;


}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<Interval> v;
        for (int i = 0; i < n; i++)
        {
            int x, y, h;
            cin >> x >> y >> h;
            Interval e={x,y,h};
            // e.x = x;
            // e.y = y;
            // e.h = h;
            v.push_back(e);
        }

        float *dp=new float[n];
        dp[0]=v[0].h;

        // cout<<maxHap(v)<<endl;
        cout << fixed << setprecision(6) <<maxHap(v)<<endl;
    }
    return 0;
}