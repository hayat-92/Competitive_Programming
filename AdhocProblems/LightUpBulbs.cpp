#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;


int main()
{
	long long n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	long long count = 0;
	if(s[0]=='0')
	{
		count = 1;
	}
	for(long long i=1; i<n; i++)
	{
		if((s[i-1]=='1') && (s[i]=='0'))
		{
			count += 1;
		}
	}
	
	if(count==0)
	{
		cout << 0;
	}
	else
	{
		cout << (count-1) * min(x, y) + y;
	}
    return 0;
}