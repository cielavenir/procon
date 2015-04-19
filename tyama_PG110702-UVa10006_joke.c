//tyama070528carmic.c
#include <stdio.h>

int solve(unsigned num){
//参考文献:http://www.research.att.com/~njas/sequences/A002997
 switch(num){
case 561:
case 1105:
case 1729:
case 2465:
case 2821:
case 6601:
case 8911:
case 10585:
case 15841:
case 29341:
case 41041:
case 46657:
case 52633:
case 62745:
case 63973:
   return 1;
 }
 return 0;
}

int main(){
  unsigned u;

  begin:
  u=0;
  scanf("%u", &u);
  if(!u)return 0;
  printf(solve(u) ? "The number %u is a Carmichael number.\n" : "%u is normal.\n", u);
  goto begin;
}