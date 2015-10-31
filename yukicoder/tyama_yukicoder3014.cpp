#include <string>
#include <unordered_map>
#include <climits>
#include <cstdio>
#include <unistd.h>
#define lrotl(val,rot) (( (val)<<(rot) )|( (val)>>(sizeof(val)*CHAR_BIT-(rot)) ))

const int N=14;

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

long long P,B;
long long calc(const std::string &s){
	long long r=0;
	__int128_t b=1;
	int l=s.size();
	for(int i=0;i<s.size();i++){
		r=(r+b*s[l-i-1])%P;
		b=(b*B)%P;
	}
	return r;
}
int main(){
#if 0
	xor_srand((unsigned int)time(NULL)^(getpid()<<16));
	//scanf("%lld%lld",&P,&B);
	P=1000000000000000003;
	B=123456789987654321;
	std::unordered_map<long long,std::string>h;
	long long cnt=0;
	for(;;cnt++){
		if(cnt%1000000==0)fprintf(stderr,"%lld\n",cnt);
		std::string x;
		for(int i=0;i<N;i++)x+='a'+xor_rand()%26;
		long long v=calc(x);
		if(h.find(v)!=h.end()){
			if(h[v]!=x){
				puts(h[v].c_str());
				puts(x.c_str());
				break;
			}
		}else{
			h[v]=x;
		}
	}
#else
	//328M steps
	puts("wldvxcyhlsptef");
	puts("jnargjrvmnuhzy");
#endif
}