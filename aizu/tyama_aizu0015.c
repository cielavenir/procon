#include <stdio.h>

/// dlfcn.h ///
#ifdef __cplusplus
extern "C"{
#endif
#if defined(WIN32) || (!defined(__GNUC__) && !defined(__clang__))
	void* LoadLibraryA(const char *x);
	void* GetProcAddress(void *x,const char *y);
	int   FreeLibrary(void *x);
#elif defined(__APPLE__)
	void* dlopen(const char *x,int y);
	void* dlsym(void *x,const char *y);
	int   dlclose(void *x);
	#define LoadLibraryA(s) dlopen(s,2)
	#define GetProcAddress dlsym
	#define FreeLibrary dlclose
#else
	void* __libc_dlopen_mode(const char *x,int y);
	void* __libc_dlsym(void *x,const char *y);
	int   __libc_dlclose(void *x);
	#define LoadLibraryA(s) __libc_dlopen_mode(s,2)
	#define GetProcAddress __libc_dlsym
	#define FreeLibrary __libc_dlclose
#endif
#ifdef __cplusplus
}
#endif

#include "gmp.h"
typedef void (*type_mpz_init)(mpz_t);
typedef void (*type_mpz_clear)(mpz_t);
typedef void (*type_mpz_out_str)(FILE*,int,mpz_t);
typedef void (*type_mpz_set)(mpz_t,mpz_t);
typedef void (*type_mpz_set_str)(mpz_t,char*,int);
typedef void (*type_mpz_set_si)(mpz_t,long);
typedef int  (*type_mpz_cmp)(mpz_t,mpz_t);
typedef int  (*type_mpz_cmp_si)(mpz_t,long);

typedef void (*type_mpz_add)(mpz_t,mpz_t,mpz_t);
typedef void (*type_mpz_sub)(mpz_t,mpz_t,mpz_t);
typedef void (*type_mpz_mul)(mpz_t,mpz_t,mpz_t);
typedef void (*type_mpz_tdiv_q)(mpz_t,mpz_t,mpz_t);
typedef void (*type_mpz_tdiv_r)(mpz_t,mpz_t,mpz_t);
typedef void (*type_mpz_add_ui)(mpz_t,mpz_t,long);
typedef void (*type_mpz_sub_ui)(mpz_t,mpz_t,long);
typedef void (*type_mpz_mul_ui)(mpz_t,mpz_t,long);
typedef void (*type_mpz_tdiv_q_ui)(mpz_t,mpz_t,long);
typedef void (*type_mpz_tdiv_r_ui)(mpz_t,mpz_t,long);

type_mpz_init mympz_init;
type_mpz_clear mympz_clear;
type_mpz_out_str mympz_out_str;
type_mpz_set mympz_set;
type_mpz_set_str mympz_set_str;
type_mpz_set_si mympz_set_si;
type_mpz_cmp mympz_cmp;
type_mpz_cmp_si mympz_cmp_si;

type_mpz_add mympz_add;
type_mpz_sub mympz_sub;
type_mpz_mul mympz_mul;
type_mpz_tdiv_q mympz_tdiv_q;
type_mpz_tdiv_r mympz_tdiv_r;
type_mpz_add_ui mympz_add_ui;
type_mpz_sub_ui mympz_sub_ui;
type_mpz_mul_ui mympz_mul_ui;
type_mpz_tdiv_q_ui mympz_tdiv_q_ui;
type_mpz_tdiv_r_ui mympz_tdiv_r_ui;

int main(){
	//MacPorts
	//void *H=LoadLibraryA("/opt/local/lib/libgmp.dylib");
	//ideone
	//void *H=LoadLibraryA("/usr/lib/i386-linux-gnu/libgmp.so.10");
	//paiza.io/atcoder
	//void *H=LoadLibraryA("/usr/lib/x86_64-linux-gnu/libgmp.so.10");
	//wandbox/yukicoder
	//void *H=LoadLibraryA("/usr/lib64/libgmp.so.10");
	//AOJ
	void *H=LoadLibraryA("/usr/lib64/libgmp.so.3");

	mympz_init=(type_mpz_init)GetProcAddress(H,"__gmpz_init");
	mympz_clear=(type_mpz_clear)GetProcAddress(H,"__gmpz_clear");
	mympz_out_str=(type_mpz_out_str)GetProcAddress(H,"__gmpz_out_str");
	mympz_set=(type_mpz_set)GetProcAddress(H,"__gmpz_set");
	mympz_set_str=(type_mpz_set_str)GetProcAddress(H,"__gmpz_set_str");
	mympz_set_si=(type_mpz_set_si)GetProcAddress(H,"__gmpz_set_si");
	mympz_cmp=(type_mpz_cmp)GetProcAddress(H,"__gmpz_cmp");
	mympz_cmp_si=(type_mpz_cmp_si)GetProcAddress(H,"__gmpz_cmp_si");

	mympz_add=(type_mpz_add)GetProcAddress(H,"__gmpz_add");
	mympz_sub=(type_mpz_sub)GetProcAddress(H,"__gmpz_sub");
	mympz_mul=(type_mpz_mul)GetProcAddress(H,"__gmpz_mul");
	mympz_tdiv_q=(type_mpz_tdiv_q)GetProcAddress(H,"__gmpz_tdiv_q");
	mympz_tdiv_r=(type_mpz_tdiv_r)GetProcAddress(H,"__gmpz_tdiv_r");

	mympz_add_ui=(type_mpz_add_ui)GetProcAddress(H,"__gmpz_add_ui");
	mympz_sub_ui=(type_mpz_sub_ui)GetProcAddress(H,"__gmpz_sub_ui");
	mympz_mul_ui=(type_mpz_mul_ui)GetProcAddress(H,"__gmpz_mul_ui");
	mympz_tdiv_q_ui=(type_mpz_tdiv_q_ui)GetProcAddress(H,"__gmpz_tdiv_q_ui");
	mympz_tdiv_r_ui=(type_mpz_tdiv_r_ui)GetProcAddress(H,"__gmpz_tdiv_r_ui");

	mpz_t a,b,c;
	mympz_init(a);
	mympz_init(b);
	mympz_init(c);
	mympz_set_str(c,"100000000000000000000000000000000000000000000000000000000000000000000000000000000",10);

	char A[101],B[101];

	int T;
	for(scanf("%d",&T);T--;){
		scanf("%s%s",A,B);
		mympz_set_str(a,A,10);
		mympz_set_str(b,B,10);
		mympz_add(a,a,b);
		if(mympz_cmp(a,c)>=0){
			puts("overflow");
		}else{
			mympz_out_str(stdout,10,a);
			puts("");
		}
	}

	mympz_clear(a);
	mympz_clear(b);
	mympz_clear(c);

	FreeLibrary(H);
}