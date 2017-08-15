#include <random>
#include <ctime>
#include <cstdio>
#include <unistd.h>

int main(){
	std::mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	std::uniform_int_distribution<int> nrange(1,100),raterange(1500,4000);
	int n=nrange(engine);
	printf("%d\n",n);
	for(int i=0;i<n;i++)printf("%d\n",raterange(engine));
}
