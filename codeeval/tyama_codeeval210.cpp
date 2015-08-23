#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
unsigned char *a;

void execute(const char *p){
  char c;
  int i=0,marker;
  while(c=*(p+i)){
    i++;
    switch(c){
      case '>': a++;break;
      case '<': a--;break;
      case '+': (*a)++;break;
      case '-': (*a)--;break;
      case '.': putchar(*a);break;
      case ',': *a=getchar();break;
      case '[': if(*a)execute(p+i);
                marker=1;
                while(marker){
                  if(*(p+i)=='[')marker++;
                  if(*(p+i)==']')marker--;
                  i++;
                }
                break;
      case ']': if(*a)i=0;else return;break;
      case 0: return;
    }
  }
}

int main(){
	string line,s;
	for(;getline(cin,line);){
		unsigned char *da=(unsigned char*)malloc(0x20000);
		for(int i=0;i<0x20000;i++)da[i]=0;
		a=da+0x10000;
		execute(line.c_str());
		puts("");
		free(da);
	}
}