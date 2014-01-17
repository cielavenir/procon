#include <stdio.h>

int count(int x){

 return -(x+1)/x+4;

}

int main(){

 for( int i=1 ; i-1001 ; i++ ) printf("%d %d\n",i,count(i));

 return 0;

}