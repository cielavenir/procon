#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#include <limits.h>
//I hope (sizeof(val)*CHAR_BIT-(rot)) will be precalculated in compilation.
//#define lrotr(val,rot) (( (val)<<(sizeof(val)*CHAR_BIT-(rot)) )|( (val)>>(rot) ))
#define lrotl(val,rot) (( (val)<<(rot) )|( (val)>>(sizeof(val)*CHAR_BIT-(rot)) ))

static unsigned int x = 123456789;
static unsigned int y = 362436069;
static unsigned int z = 521288629;
static unsigned int w = 88675123; 

unsigned int xor_rand(){
	unsigned int t;
	t=x^(x<<11);
	x=y;y=z;z=w;
	return w=(w^(w>>19)) ^ (t^(t>>8));
}

// http://d.hatena.ne.jp/gintenlabo/20100930/1285859540
void xor_srand(unsigned int seed){
#if 1
	x^=seed;
	y^=lrotl(seed,17);
	z^=lrotl(seed,31);
	w^=lrotl(seed,18);
#else
	x^=lrotl(seed,14);
	y^=lrotl(seed,31);
	z^=lrotl(seed,13);
	w^=seed;
#endif
}

double algo1(const int N,const vpii &v){
	double R=0,r1,r0;
	int c=0,i=1,j,next1;
	set<int>s;
	s.insert(c);
	for(;i<N;i++){
		r1=999999999;
		for(j=0;j<N;j++){
			if(s.find(j)==s.end()&&(r0=hypot(v[c].first-v[j].first,v[c].second-v[j].second))<r1)r1=r0,next1=j;
		}
		R+=r1,c=next1,s.insert(c);
	}
	return R;
}
double algo2(const int N,const vpii &v){
	double R=0,r1,r2,r0;
	int c=0,i=1,j,next1,next2;
	set<int>s;
	s.insert(c);
	for(;i<N-2;i++){
		r1=r2=999999999;
		for(j=0;j<N;j++){
			if(s.find(j)==s.end()){
				r0=hypot(v[c].first-v[j].first,v[c].second-v[j].second);
				if(r0<r1)r2=r1,next2=next1,r1=r0,next1=j;
				else if(r0<r2)r2=r0,next2=j;
			}
		}
		R+=r2,c=next2,s.insert(c);
	}
	for(;i<N;i++){
		r1=999999999;
		for(j=0;j<N;j++){
			if(s.find(j)==s.end()&&(r0=hypot(v[c].first-v[j].first,v[c].second-v[j].second))<r1)r1=r0,next1=j;
		}
		R+=r1,c=next1,s.insert(c);
	}
	return R;
}
int main(int argc, char **argv){
	if(argc>1&&!strcmp(argv[1],"test")){
		double d1,d2;
		int N,i=0,x,y;
		vpii v;
		for(scanf("%d",&N);i<N;i++)scanf("%d%d",&x,&y),v.push_back(make_pair(x,y));
		d1=algo1(N,v);
		d2=algo2(N,v);
		printf("%f %f\n",d1,d2);
	}else{
		unsigned int seed=(unsigned int)time(NULL)^(getpid()<<16);
		xor_srand(seed);
		double d1,d2;
		int N=100,n=95,i=0,x,y;
		long long counter=1;
		vpii v(N);
		for(;i<n;i++)v[i]=make_pair(i>>3,i&7);
		for(;;counter++){
			for(i=n;i<N;i++)v[i]=make_pair(xor_rand()%9990+10,xor_rand()%9990+10);
			d1=algo1(N,v);
			d2=algo2(N,v);
			//printf("%f %f\n",d1,d2);
			if(d1>d2)break;
		}
		fprintf(stderr,"Completed in try %lld:\n",counter);
		printf("%d\n",N);
		for(i=0;i<N;i++)printf("%d %d\n",v[i].first,v[i].second);
	}
}
/*
Completed in try 217143:
100
0 0
0 1
0 2
0 3
0 4
0 5
0 6
0 7
1 0
1 1
1 2
1 3
1 4
1 5
1 6
1 7
2 0
2 1
2 2
2 3
2 4
2 5
2 6
2 7
3 0
3 1
3 2
3 3
3 4
3 5
3 6
3 7
4 0
4 1
4 2
4 3
4 4
4 5
4 6
4 7
5 0
5 1
5 2
5 3
5 4
5 5
5 6
5 7
6 0
6 1
6 2
6 3
6 4
6 5
6 6
6 7
7 0
7 1
7 2
7 3
7 4
7 5
7 6
7 7
8 0
8 1
8 2
8 3
8 4
8 5
8 6
8 7
9 0
9 1
9 2
9 3
9 4
9 5
9 6
9 7
10 0
10 1
10 2
10 3
10 4
10 5
10 6
10 7
11 0
11 1
11 2
11 3
11 4
11 5
11 6
1221 517
206 1991
2113 1042
7679 3832
3993 1266

real 1m36.082s
user 1m35.728s
sys  0m0.087s

pbpaste|./a.out test # => 15890.767844 15599.875700
*/
