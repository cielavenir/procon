#include <vector>
#include <cstdio>
using namespace std;

void solve(){
  int l,o,x;
  vector<int> v;
  vector<int>::iterator i;
  char c;

  scanf("%d%d",&l,&o);
  for(;l--;scanf("%d",&x),v.push_back(x));
  for(;o--;){
    scanf(" %c",&c);
    switch(c){
      case 'A':
        scanf("%d",&x);
        for(i=v.begin();i!=v.end();){
          if(*i==x)v.erase(i);
          else i++;
        }
        break;
      case 'B':
        scanf("%d",&x);
        if(v.size()<x)break;
        for(i=v.begin()+x-1;i!=v.end();){
          v.erase(i);
          for(l=x-1;l--;i++)
            if(i==v.end())break;
        }
        break;
      case 'C':
        for(i=v.begin();i!=v.end();i++){
          if(i!=v.begin())printf(" ");
          printf("%d",*i);
        }
        puts("");
    }
  }
}

int main(){int i;for(scanf("%d",&i);i--;solve(),puts(""));return 0;}