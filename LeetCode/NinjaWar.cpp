// #include<bits/stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;
void checkExcitedPair(int n)
{
    int x = 1;
    bool flag = false;
     
  
    while (x * (x + 1) < n * 2)
    {
        
        int val = x * (x + 1);
         
        int t = n * 2 - val;
        int fnl = sqrt(t);
         
        if (fnl * (fnl + 1) == t)
        {
            flag = true;
            break;
        }
        x += 1;
    }
     
    if (flag)
        cout << "YES";
    else
        cout << "NO";
}
 int main()
{
    int n;
    cin>>n;
     
    checkExcitedPair(n);
 
    return 0;
}