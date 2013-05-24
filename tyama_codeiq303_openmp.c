//gcc -fopenmp -O3 tyama_codeiq303_openmp.c tyama_codeiq303_sha1.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_max_threads() 1
#define omp_get_thread_num() 0
#endif

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

;
unsigned long long getsign(unsigned long long count,unsigned long long skips){
	unsigned long long *data=(unsigned long long*)calloc(omp_get_max_threads()*65536,sizeof(unsigned long long));
	unsigned long long i,j;
	//printf("%d\n",omp_get_max_threads());

	//get data (bucket sort)
#pragma omp parallel for
	for(i=0;i<count;i+=10)
	{
		char buf[99];
		unsigned char digest[20];
		struct sha1_ctxt sha1ctx;
		unsigned long long q=i/10,r;
		sprintf(buf,LLU,q);
		sha1_init(&sha1ctx);
		sha1_loop(&sha1ctx,buf,strlen(buf));
		sha1_result(&sha1ctx,digest);
		unsigned short n;
		for(r=0;r<10;r++)data[omp_get_thread_num()*65536+((digest[2*r]<<8)|digest[2*r+1])]++;
	}

	{
		char buf[99];
		unsigned char digest[20];
		struct sha1_ctxt sha1ctx;
		unsigned long long q=count/10,r;
		sprintf(buf,LLU,q);
		sha1_init(&sha1ctx);
		sha1_loop(&sha1ctx,buf,strlen(buf));
		sha1_result(&sha1ctx,digest);
		for(r=0;r<count%10;r++)data[(digest[2*r]<<8)|digest[2*r+1]]++;
	}

	//implement own reduction...
	for(i=1;i<omp_get_max_threads();i++)for(j=0;j<65536;j++)data[j]+=data[i*65536+j];

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
	free(data);
	return sum;
}
int main(){
	//printf(LLU"\n",getsign(100,10)); //284067
	//printf(LLU"\n",getsign(100000000,1000)); //3276658109
	printf(LLU"\n",getsign(107374182400,16777216)); //7m47.447s 209679232
}