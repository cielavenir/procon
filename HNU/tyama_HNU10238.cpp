#include <map>
#include <cstdio>
using namespace std;

int main(){
  map<unsigned, bool> s;
  unsigned i=0,n;
  for(;i<65536;i++)
    s[(i*(i+1))/2]=true;
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d",&i);
    putchar(s[i-1]?'1':'0');
    if(n>1)printf(" ");
  }
  return 0;
}