#pragma GCC optimize("O3")
#pragma GCC target("avx")

#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

//#define CODEEVAL191

#ifdef CODEEVAL191
char str[999];
typedef __uint128_t val_t;
int popcnt(const val_t &x){int r=0;val_t z=x;for(;z;z/=2)r+=z%2;return r;}
#else
typedef unsigned long long val_t;
#define popcnt __builtin_popcountll
#endif

int lightsout(int x,int y){
	vector<vector<val_t>>a(x*y);
	for(int i=0;i<x*y;i++)a[i].resize(2);

	//create problem
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			a[i+j*x][0]=(val_t)1<<(i+j*x);
			a[i+j*x][1]= 0 +
				((val_t)1<<(i+j*x)) |
				(i>0   ? (val_t)1<<(i-1+j*x) : 0) |
				(i<x-1 ? (val_t)1<<(i+1+j*x) : 0) |
				(j>0   ? (val_t)1<<(i+(j-1)*x) : 0) |
				(j<y-1 ? (val_t)1<<(i+(j+1)*x) : 0) |
#ifndef CODEEVAL191
				(i>0   && j>0   ? (val_t)1<<(i-1+(j-1)*x) : 0) |
				(i<x-1 && j>0   ? (val_t)1<<(i+1+(j-1)*x) : 0) |
				(i>0   && j<y-1 ? (val_t)1<<(i-1+(j+1)*x) : 0) |
				(i<x-1 && j<y-1 ? (val_t)1<<(i+1+(j+1)*x) : 0) |
#endif
				0;
		}
	}

	//solve
	val_t badbits=0;
	int i=0;
	for(;i<x*y;i++){
		if((a[i][1]&((val_t)1<<i))==0){
			int j=i+1;
			for(;j<x*y;j++){
				if((a[j][1]&((val_t)1<<i))!=0){
					swap(a[i],a[j]);
					break;
				}
			}
			if(j==x*y){
				badbits|=(val_t)1<<i;
				continue;
			}
		}

		for(int j=0;j<x*y;j++){
			if(i==j)continue;
			if((a[j][1]&((val_t)1<<i))!=0){
				a[j][0]^=a[i][0];
				a[j][1]^=a[i][1];
			}
		}
	}
	int k=x*y-popcnt(badbits);
	fprintf(stderr,"quiet pattern=%d\n",x*y-k);

	//0解(quiet pattern)の集合tを用意する
	val_t tmsk=0;
	vector<val_t>t;
	vector<pair<int,val_t>>a_ok;
	for(int i=0;i<x*y;i++){
		if((badbits>>i)&1){
			t.push_back(a[i][0]);
		}else{
			a_ok.emplace_back(i,a[i][0]);
			tmsk|=(val_t)1<<i;
		}
	}

	//入力・解の存在判定
#ifdef CODEEVAL191
	scanf("%s",str);
#endif
	val_t input=0;
	for(int i=0;i<x*y;i++){
		int t;
#ifdef CODEEVAL191
		t=str[i%x+i/x*(x+1)]=='O';
#else
		scanf("%d",&t);
#endif
		input|=(val_t)t<<i;
	}
	if(any_of(t.begin(),t.end(),[&](val_t &e)->bool{
		return popcnt(e&input)&1;
	})){
		return -1;
	}

	vector<val_t>tlst(1<<(x*y-k)); // このメモリはあまり大きくならないはず
	for(val_t l=0;l<1<<(x*y-k);l++){
		val_t r=0;
		for(int j=0;j<x*y-k;j++)if(l&((val_t)1<<j))r^=t[j];
		tlst[l]=r;
	}

	val_t r0=1<<29;
	val_t c0=0;
	for(auto &j:a_ok)if(input&((val_t)1<<j.first))c0^=j.second;
	//0解の重ね合わせをすべて試す
	#pragma omp parallel for reduction(min:r0)
	for(val_t l=0;l<(val_t)1<<(x*y-k);l++){
		val_t r1=c0;
		//for(int j=0;j<x*y-k;j++)if(l&((val_t)1<<j))r1^=t[j];
		r1^=tlst[l];
		r0=min(r0,(val_t)popcnt(r1));
	}
	return r0;
}

int main(int argc, char **argv){
#ifdef CODEEVAL191
	if(argc>1)freopen(argv[1],"rb",stdin);
#endif
	int m,n;
	for(;~scanf("%d%d",&m,&n);){
		int r=lightsout(n,m);
		if(r<0){
#ifdef CODEEVAL191
			puts("Impossible");
#else
			puts("-1");
#endif
		}else{
			printf("%d\n",r);
		}
	}
}
