#include<iostream>
using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int k=0;
//         for(int i=1; i<=n; i++){
//             k=k^i;
//         }
//         cout<<k<<endl;
//     }
//     return 0;
// }


int main() {
  long long T, N, i, ans;

  cin >> T;
  while(T--) {
    cin >> N;

    switch(N % 4) {
      case 0: ans = N; break;
      case 1: ans = 1; break;
      case 2: ans = N + 1; break;
      case 3: ans = 0; break;
    }

    cout << ans << endl;
  }

  return 0;
}