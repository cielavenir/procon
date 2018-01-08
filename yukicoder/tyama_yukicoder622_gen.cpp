#include <random>
#include <ctime>
#include <cstdio>
#include <unistd.h>

int main(){
	std::mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	std::uniform_int_distribution<int>range(-1000000,1000000);
	for(int i=0;i<12;putchar(++i%3?' ':'\n'))printf("%d",range(engine));
}
