/*
tyama070530fact_factor.c
x==(divはuの何乗を因数に持つか),y==(fact!はuの何乗を因数に持つか)
y=(uを因数に持つ数の個数)+(u*uを因数に持つ数の個数)+...、として計算する。
factをuで割った商が、2からfactまででuを因数に持つ数の個数である。
このとき、fact/div∈Nなので、x>yは不適である。

ループをu*u<=divで止めているが、u==div(<fact)になったときにすべては解決する(sqrt(div)<k<divなるkはdivの因数にはなり得ない)
u>factのとき、fact!はuを因数に持たないため、div>factならdiv==1になるにはx>y(==0)となるuが必要になり矛盾する。

I refered to Mr Yamaguchi and Mr Watanabe. Thx very much.
*/

#include <stdio.h>

int solve(unsigned div, unsigned fact){
  unsigned u=2,v,x,y;
  for(;u*u<=div;u++){
   x=y=0;
   v=fact/u;
   for(;!(div%u);div/=u,x++);
   for(;v;y+=v,v/=u);
   if(x>y)return 0;
  }
  return div<=fact;
}

int main(){
  unsigned u,t;

  begin:
  if(scanf("%u %u", &t, &u)==EOF)return 0; //u==0な入力を入れてくるとは腐ったテストだwww
  printf((u==1&&t==0)||(u&&solve(u,t)) ? "%u divides %u!\n" : "%u does not divide %u!\n", u, t); //u!=0を先に判定する(短絡)
  goto begin;
}