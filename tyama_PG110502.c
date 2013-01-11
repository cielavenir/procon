//tyama070521reverse.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
reverse()の設計ミス。place()もpower()も不必要でした。

int place(unsigned u){
  unsigned t=u/10;
  if(!t)return 0;
  return (place(t))+1;
/*asmが使えれば絶対その方が早い。Cだと++がコンパイルエラーにw
  __asm{
  xor edx,edx
  mov eax, u
  div 10
  test eax, 0
  jz @return
  push eax
  call place
  inc eax
  ret
  @return
  xor eax, eax
  ret
  }
*/
}

//マイコンクラブのscheme講習会で作ったものの移植w
unsigned power(unsigned u, int i){
  if(!i)return 1;
  return u*power(u,--i);
}
#endif

unsigned reverse(unsigned u){
  unsigned ret=0;
  while(u){
    ret=ret*10+u%10;
    u/=10;
  }
  return ret;
}

void main(){
  unsigned u;
  int i,n,count;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    count=0;
    scanf("%u", &u);
    while(u!=reverse(u)){
      u+=reverse(u);
      count++;
    }
    printf("%d %u\n",count,u);
  }
}