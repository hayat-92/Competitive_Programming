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

#include <iostream>
using namespace std;

int main(){
    int y = 1;
    if(y & (y = 2)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}