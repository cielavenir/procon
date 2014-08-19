#include <iostream>
#include <string>
#include <bitset>
#include <cstring>
using namespace std;

const char *t1=" ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *v1[]={"101","000000","000011","10010001","010001","000001","100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
const char *t2="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";

int main(){
  string s,t,z;
  int i,j;
  for(;z=t="",getline(cin,s);cout<<t<<endl){
    for(i=0;i<s.size();i++)
      if((j=strchr(t1,s[i])-t1)+t1)z+=v1[j];
    for(;z.size()%5;z+='0');
    for(i=0;i<z.size()/5;i++)
      t+=t2[bitset<5>(z,i*5,i*5+5).to_ulong()];
  }
}