#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int longestPalindrome(vector<string> &words)
{
    map<string, int> mp;
    for (int i = 0; i < words.size(); i++)
    {
        mp[words[i]]++;
    }

     map<string, int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++){
        if((*it).second){

        }
    }
}