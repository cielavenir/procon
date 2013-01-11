#include <cstdio>
#include <stack>

int main(){
  std::stack<int>s;
  for(int x;~scanf("%d",&x);)
    if(x)s.push(x);
    else printf("%d\n",s.top()),s.pop();
}