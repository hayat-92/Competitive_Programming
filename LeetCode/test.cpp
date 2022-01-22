#include <iostream>
using namespace std;

// int main(){
//     cout<<~0<<endl;
//     if(~0 == 1) {
//         cout << "yes";
//     }
//     else {
//         cout << "no";
//     }
// }
int main(){
    int y = 0;
    if(0 | (y = 1)) {
        cout << "y is " << y;
    }
    else {
        cout << y;
    }
}