#include <map>
#include <random>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;

int main(){
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	uniform_int_distribution<int> gen_num(2,2100000000);
	int N=10000;
	int gen=0;
	printf("%d\n",N);
	for(;gen<N;){
		int a=gen_num(engine),b=gen_num(engine);
		if((long long)a*b<10)continue;
		printf("%d %d\n",a,b);
		gen++;
	}
}	
