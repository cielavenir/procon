#include <stdio.h>
#include <math.h>
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

int main(){
	//void *H=LoadLibraryA("/usr/local/lib/gcc/9/libquadmath.dylib");
	void *H=LoadLibraryA("/usr/lib/x86_64-linux-gnu/libquadmath.so.0");
	mysqrtq=(type_sqrtq)GetProcAddress(H,"sqrtq");
	myquadmath_snprintf=(type_quadmath_snprintf)GetProcAddress(H,"quadmath_snprintf");

	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	//puts(sqrtl(a)+sqrtl(b)<sqrtl(c) ? "Yes" : "No");
	puts(mysqrtq(a)+mysqrtq(b)<mysqrtq(c) ? "Yes" : "No");
}
