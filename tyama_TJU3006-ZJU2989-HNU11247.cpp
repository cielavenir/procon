#include <string.h>
#include <iostream>

using namespace std;

char str[100];
char code[500];
char enc[500];
char t[28]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int x,y;

void encode(){
  int xi=0,xa=x,yi=0,ya=y,i=0,j=0,c=0;
  while(c<x*y-1){
    for(;i<xa-1;i++)
      enc[x*j+i]=code[c++];
    for(;j<ya-1;j++)
      enc[x*j+i]=code[c++];
    if(c>=x*y-1)break;
    for(;i>xi;i--)
      enc[x*j+i]=code[c++];
    for(;j>yi+1;j--)
      enc[x*j+i]=code[c++];
    xi++;yi++;xa--;ya--;
  }
  enc[x*j+i]=code[c];
}

void get(int j){
  char *p=strchr(t,str[j+1]);
  code[j*5]=((*p>>4)&1)+'0';
  code[j*5+1]=((*p>>3)&1)+'0';
  code[j*5+2]=((*p>>2)&1)+'0';
  code[j*5+3]=((*p>>1)&1)+'0';
  code[j*5+4]=(*p&1)+'0';
}

int main(){
  int i,n,j,s;
  cin >> n;
  for(i=1;i<=n;i++){
    cout << i << " ";
    cin >> y >> x;
    cin.getline(str,100);
    s=strlen(str+1);
    memset(code,0,sizeof(code));
    memset(enc,0,sizeof(enc));
    for(j=0;j<s;j++)
      get(j);
    for(j*=5;j<x*y;j++)code[j]='0';

    encode();
    cout << enc << endl;
  }
  return 0;
}