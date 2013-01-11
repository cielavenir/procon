//tyama_mugenloop_A.c
//070702

#include <stdio.h>
#include <stdlib.h>

char list[100]; //n < 50, so char is ok.

int main(){
  int n, q, m, a, x, i;

  for(;scanf("%d%d",&n,&q),n||q;){
    q--;
    for(i=0;i<n;i++){
      scanf("%d",&m);
      for(a=0;a<m;a++){
        scanf("%d", &x);
        list[x]++;
      }
    }

    a=0;
    for(i=0;i<100;i++){
	  if(list[i]>q){
	    a=i;q=list[i];
	  }
	  list[i]=0;
    }
    printf("%d\n", a);
  }
}