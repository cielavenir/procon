#include <stdio.h>

int count(int x){

 return 2|!!~-x;

}

int main(){for(int i=1;i^10001;i++)printf("%d %d\n",i,count(i));return 0;}