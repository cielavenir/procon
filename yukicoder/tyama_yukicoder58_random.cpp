#include <vector>
#include <random>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	int T=2000000;
	int S=0;
	uniform_int_distribution<int> gooddice(1,6);
	uniform_int_distribution<int> badddice(4,6);
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	for(int I=0;I<T;I++){
		int a=0,b=0,i=0;
		for(;i<K;i++)a+=gooddice(engine),b+=badddice(engine);
		for(;i<N;i++)a+=gooddice(engine),b+=gooddice(engine);
		if(a<b)S++;
	}
	printf("%f\n",S*1.0/T);
}