//tyama070528carmic.c
#include <stdio.h>

int solve(unsigned num){
//cf:https://oeis.org/A002997
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
case 75361:
case 101101:
case 115921:
case 126217:
case 162401:
case 172081:
case 188461:
case 252601:
case 278545:
case 294409:
case 314821:
case 334153:
case 340561:
case 399001:
case 410041:
case 449065:
case 488881:
case 512461:
case 530881:
case 552721:
case 656601:
case 658801:
case 670033:
case 748657:
case 825265:
case 838201:
case 852841:
case 997633:
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
