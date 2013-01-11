#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
  fstream fin;
  fin.open(argv[1]);
  string s,t;
  int m=0,n;
  for(;fin>>s;){
    t=s="0"+s;
    while(strcmp(s.c_str(),t.c_str())<=0){
      next_permutation(s.begin(),s.end());
    }
    if(s[0]=='0')s=s.substr(1);
    cout<<s<<endl;
  }
}