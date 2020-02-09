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

typedef __float128 (*type_strtoflt128)(const char*, char**);
typedef int (*type_quadmath_snprintf)(char *s, size_t size, const char *format, ...);
type_strtoflt128 mystrtoflt128;
type_quadmath_snprintf myquadmath_snprintf;

char buf[99];
int main(){
	//void *H=LoadLibraryA("/usr/local/lib/gcc/9/libquadmath.dylib");
	void *H=LoadLibraryA("/usr/lib64/libquadmath.so");
	mystrtoflt128=(type_strtoflt128)GetProcAddress(H,"strtoflt128");
	myquadmath_snprintf=(type_quadmath_snprintf)GetProcAddress(H,"quadmath_snprintf");
	int N,i=0;
	scanf("%d",&N);
	__float128 s=0;
	for(;i<N;i++){
		scanf("%s",buf);
		s+=mystrtoflt128(buf,NULL);
	}
	myquadmath_snprintf(buf,sizeof(buf),"%.10Qf",s);
	puts(buf);
	return 0;
}
