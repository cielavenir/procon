#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
main(){
	srand(time(NULL)^(getpid()<<16));
	printf("%d\n",rand()%2);
}