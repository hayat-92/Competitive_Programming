#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    
    // write your code here
    int n; cin >> n;
    vector<bool> sieve;
    sieve = vector<bool>(n+2, true);
    sieve[0]=false;
    sieve[1]=false;
	for(int i = 2 ; i*i <= n+1 ; ++i) {
		if(sieve[i]) {
			for(int j = i*i ; j < n+2 ; j += i) {
				sieve[j] = false;
			}
		}
	}

	if(n <= 1) {
		cout << 1 << '\n';
	}
	else {
		cout << 2 << '\n';
	}

	int cp = 0, cnp = 0;
	for(int i = 2 ; i <= n+1 ; ++i) {
		if(sieve[i]) ++cp;
		else ++cnp;
	}

	cout << min(cp, cnp) << ' ' << max(cp, cnp) << '\n';

    return 0;
}