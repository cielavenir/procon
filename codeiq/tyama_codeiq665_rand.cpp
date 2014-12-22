#include <vector>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;
int N;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
bool ok(int x,int y){return min(x,y)==gcd(x,y);}
bool frozen(vector<int> &v){ //全てのi,jについて、min(v[i],v[j])はmax(v[i],v[j])の約数
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++)if(!ok(v[i],v[j]))return false;
	}
	return true;
}
void output(vector<int> &v){
	for(int i=0;i<N;i++)printf("%d ",v[i]);
	puts("");
}
int main(int argc, char **argv){
	if(argc<2){
		printf("give me array size\n");
		return 1;
	}
	N=strtol(argv[1],NULL,10);
	uniform_int_distribution<int> distribution(2,N-1);
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	int m=N*N;
	int t,i,n;
	for(t=0;t<100000000;t++){ //monte carlo simulation (100 million times)
		vector<int>v(N);
		for(i=0;i<N;i++){
			v[i]=i+1;
		}
		for(n=0;n<m&&!frozen(v);n++){ //nは高々m
			for(;;){
				int a=distribution(engine);
				int b=distribution(engine);
				if(!ok(v[a],v[b])){
					int g=gcd(v[a],v[b]);
					v[b]*=v[a]/g;
					v[a]=g;
					break;
				}
			}
		}
		if(m>n)printf("Found %d in try %d\n",n,t);
		m=n;
	}
	printf("%d\n",m); //12回
}
/*
possibly:
0 0 1 1 2 2  3  4  4  5
6 6 7 8 9 9 10 11 12 12

Found 27 in try 0
Found 24 in try 1
Found 21 in try 2
Found 18 in try 4
Found 17 in try 142
Found 16 in try 217
Found 15 in try 4181
Found 14 in try 30536
Found 13 in try 644573
Found 12 in try 760597
*/