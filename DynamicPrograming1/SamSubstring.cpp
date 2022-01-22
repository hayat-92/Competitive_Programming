#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int substrings(string n) {

    long m=pow(10,9)+7;

    long sum=n[0]-'0';
    long tsum=n[0]-'0';
    for(int i=1; i<n.length(); i++){
        int k=n[i]-'0';
        sum=(sum*10+(k*(i+1)))%m;
        tsum=(tsum+sum)%m;
    }

    return tsum;

}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    // getline(cin, n);
    cin>>n;

    int result = substrings(n);

    cout << result << "\n";

    // cout.close();

    return 0;
}
