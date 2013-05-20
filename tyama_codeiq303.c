#include <stdio.h>
#include <string.h>

//#include "sha1.h"
#include <stdint.h>
struct sha1_ctxt {
	union {
		uint8_t	b8[20];
		uint32_t	b32[5];
	} h;
	union {
		uint8_t	b8[8];
		uint64_t	b64[1];
	} c;
	union {
		uint8_t	b8[64];
		uint32_t	b32[16];
	} m;
	uint8_t	count;
};
void sha1_init(struct sha1_ctxt *ctxt);
void sha1_loop(struct sha1_ctxt *ctxt,const uint8_t *input,size_t len);
void sha1_result(struct sha1_ctxt *ctxt,uint8_t *digest);

#if defined(WIN32) || (!defined(__GNUC__) && !defined(__clang__))
	#define LLU "%I64u"
#else
	#define LLU "%llu"
#endif

static char buf[99];
static unsigned char digest[20];
static unsigned short GETDATA2[10];
static struct sha1_ctxt sha1ctx;
void getdata2(unsigned long long q){
	sprintf(buf,LLU,q);
	sha1_init(&sha1ctx);
	sha1_loop(&sha1ctx,buf,strlen(buf));
	sha1_result(&sha1ctx,digest);
	int i=0;
	for(i=0;i<10;i++)GETDATA2[i]=(digest[2*i]<<8)|digest[2*i+1];
}
unsigned short getdata(unsigned long long index){
	unsigned long long q=index/10,r=index%10;
	getdata2(q);
	return GETDATA2[r];
}

unsigned long long data[65536];
unsigned long long getsign(unsigned long long count,unsigned long long skips){
	memset(data,0,sizeof(data));
	unsigned long long i=0,q,r;

	//get data (bucket sort)
	for(;i<count;i+=10){
		q=i/10;
		getdata2(q);
		for(r=0;r<10;r++)data[GETDATA2[r]]++;
	}
	q=i/10;
	getdata2(q);
	for(r=0;r<count%10;r++)data[GETDATA2[r]]++;

	//debug
	//for(i=0;i<65536;i++)printf("[*] "LLU"\n",data[i]);

	//output
	unsigned long long sum=0,s=1,m;
	s=1;
	for(i=0;i<65536;i++){
		for(;data[i];){
			m=data[i]<s?data[i]:s;
			data[i]-=m;
			s-=m;
			if(!s){
				//printf("[+] "LLU"\n",i);
				sum+=i;
				s=skips;
			}
		}
	}
	return sum;
}
int main(){
	//printf(LLU"\n",getsign(100000000,1000)); //7.5sec
	printf(LLU"\n",getsign(107374182400,16777216)); //101m42.627s
}

/*
209679232

ソートするべき配列は長いが、その範囲は0-65535と決まっている。よって、ソートはバケットソートを選択した。
また、10で割った余りが0-9である10個のデータを一度に算出するようにした。これにより(getdata2()という関数が増えたものの)SHA1を計算する回数は1/10にすることができた。
それでも10億個のSHA1を計算しなければならないので、スクリプト言語では計算時間が膨大になってしまう。よって今回はCを選択した。
107374182400/16777216=6400、全部で6400個の足し算をすれば良い。各要素は65536未満であるから、64bit以内に収まる。
なお、実行には102分を要した(MacBookAir Core i7 / clang -O3)。
*/