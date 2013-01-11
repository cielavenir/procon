//tyama070528carmic.c
#include <stdio.h>
#include <math.h> //ŽÍ‚¹_‚æ

//ˆÈ‰ºAnum‚ÍÅ’áŒÀcarmichael‚Æ‰¼’è‚·‚éw //‚±‚Ì‰¼’è‚Ì‚½‚ß‚ ‚¦‚È‚­WA.
int solve(unsigned num){
  int x= num>3 ? 1+(int)sqrt(num) : num;
  int i=2;
  for(;i<x;i++){
   if(num/i*i==num)return num;
  }
  return 0;
}

void main(){
  unsigned u;

  begin:
  scanf("%u", &u);
  if(!u)return;
  printf(solve(u) ? "The number %u is a Carmichael number.\n" : "%u is normal.\n", u);
  goto begin;
}