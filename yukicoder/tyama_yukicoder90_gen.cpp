#include <map>
#include <random>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;

int main(){
	mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
	//uniform_int_distribution<int> gen_numitem(3,9);
	//uniform_int_distribution<int> gen_numitem(30,50);
	uniform_int_distribution<int> gen_numitem(11,14);
	int N=gen_numitem(engine);
	uniform_int_distribution<int> gen_item(0,N-1);
	uniform_int_distribution<int> gen_score(1,10000);
	int perm=N*(N-1);
	uniform_int_distribution<int> gen_numscore(3,perm);
	int Mmax=gen_numscore(engine);
	int fail=0;
	int gen=0;
	map<pair<int,int>,int> scores;
	for(;gen<Mmax&&fail<perm*10;){
		int a=gen_item(engine);
		int b=gen_item(engine);
		if(a==b||scores.find(make_pair(a,b))!=scores.end()){
			fail++;
		}else{
			scores[make_pair(a,b)]=gen_score(engine);
			gen++;
		}
	}
	printf("%d %d\n",N,scores.size());
	for(auto &e:scores)printf("%d %d %d\n",e.first.first,e.first.second,e.second);
}	