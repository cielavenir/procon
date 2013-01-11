#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <cstring>
using namespace std;

const char *t1=" ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *v1[]={"101","000000","000011","10010001","010001","000001","100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
const char *t2="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";

int main(){
  string s,t,z;
  int i,j,x;
  map<string,char>m;
  for(i=0;i<32;i++)m[string(v1[i])]=t1[i];
  for(;z=t="",getline(cin,s);cout<<t<<endl){
    for(i=0;i<s.size();i++)
      if((j=strchr(t2,s[i])-t2)+t2)z+=bitset<5>(j).to_string();
    for(x=i=0;;i+=j){
      for(j=1;i+j<=z.size();j++){
        if(m[z.substr(i,j)]){x=0;t+=m[z.substr(i,j)];break;}
      }
      if(i+j>z.size())break;
    }
  }
}