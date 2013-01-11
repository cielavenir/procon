//tyama070420hanafuda.c
//2004 domestic A
//070420

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
 int i,r,n;
 int *pVector;

 while(1){
  //input
  scanf("%d %d", &n, &r);
  if(!n&&!r) return 0; //end

  pVector=(int*)malloc(sizeof(int)*n);
  for(i=0; i<n; i++)
   pVector[i]=n-i;

  for(i=0; i<r; i++){
   int p,c,i0;
   int *pSort=(int*)malloc(sizeof(int)*n);
   scanf("%d %d", &p, &c);
   for(i0=0; i0<p-1; i0++)
    pSort[i0+c]=pVector[i0];
   for(i0=0; i0<c; i0++)
    pSort[i0]=pVector[i0+p-1];
   for(i0=p-1+c; i0<n; i0++)
    pSort[i0]=pVector[i0];
   free(pVector);
   pVector = pSort;
  }

  //output
  printf("%d\n",pVector[0]);
  free(pVector);
 }
}