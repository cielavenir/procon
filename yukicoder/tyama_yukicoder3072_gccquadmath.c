#include <stdio.h>
#include <quadmath.h>

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

typedef __float128 (*type_sqrtq)(__float128);
typedef int (*type_quadmath_snprintf)(char *s, size_t size, const char *format, ...);
type_sqrtq mysqrtq;
type_quadmath_snprintf myquadmath_snprintf;

char buf[99];
int main(){
	//void *H=LoadLibraryA("/usr/local/lib/gcc/10/libquadmath.dylib");
	void *H=LoadLibraryA("/usr/lib64/libquadmath.so");
	mysqrtq=(type_sqrtq)GetProcAddress(H,"sqrtq");
	myquadmath_snprintf=(type_quadmath_snprintf)GetProcAddress(H,"quadmath_snprintf");

	int T;
	long long x;
	__float128 d;
	for(scanf("%d",&T);T--;){
		scanf("%lld",&x);
		d+=mysqrtq(x);
		myquadmath_snprintf(buf,99,"%.16Qg",d);
		puts(buf);
	}
	return 0;
}
