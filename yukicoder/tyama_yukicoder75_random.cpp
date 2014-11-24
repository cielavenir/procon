#include <vector>
#include <random>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;

double expected(int n, int s, int t){//vector<int> b){
	int T=500000;
	int S=0;
	uniform_int_distribution<int> distribution(1,s);
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	for(int I=0;I<T;I++){
		int turn=0;
		int cur=0;
		for(;cur!=t;){
			for(int i=0;i<n;i++)cur+=distribution(engine);
			if(cur>t)cur=0;
			turn++;
		}
		S+=turn;
	}
	return S*1.0/T;
}

int main(){
	int N;
	scanf("%d",&N);
	printf("%f\n",expected(1,6,N));
}