#include<iostream>
#include<map>
using namespace std;

char firstNonRepeatingCharacter(string str) {

  // Write your code here
  map<char, int> m;
  for(int i=0; i<str.length();i++){
      m[str[i]]++;
  }

  for(int i=0; i<str.length(); i++){
      if(m[str[i]]==1){
          return str[i];
      }
  }

  return str[0];

}
