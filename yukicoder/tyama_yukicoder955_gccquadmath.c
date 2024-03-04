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
#elif defined(__APPLE__) || (defined(__GLIBC__) && ((__GLIBC__ == 2 && __GLIBC_MINOR__ >= 34) || __GLIBC__ > 2))
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
	//void *H=LoadLibraryA("/usr/local/lib/gcc/9/libquadmath.dylib");
	//void *H=LoadLibraryA("/usr/lib64/libquadmath.so");
	void *H=LoadLibraryA("/usr/lib/x86_64-linux-gnu/libquadmath.so.0");
	mysqrtq=(type_sqrtq)GetProcAddress(H,"sqrtq");
	myquadmath_snprintf=(type_quadmath_snprintf)GetProcAddress(H,"quadmath_snprintf");

	int T;
	long long a,b,c;
	__float128 d;
	//for(scanf("%d",&T);T--;){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(!a){
			if(!b)puts(c?"0":"-1");
			else printf("1\n%.12Lf\n",-c*1.0L/b);
		}else{
			if(a<0)a=-a,b=-b,c=-c;
			__float128 _a=a,_b=b,_c=c;
			d=_b*_b-4.0Q*_a*_c;
			if(d<0)puts("0");
			else if(d==0)printf("1\n%.12Lf\n",-b/2.0L/a);
			else{
				puts("2");
				myquadmath_snprintf(buf,99,"%.12Qf",(-_b-mysqrtq(d))/2/_a);
				puts(buf);
				myquadmath_snprintf(buf,99,"%.12Qf",(-_b+mysqrtq(d))/2/_a);
				puts(buf);
			}
		}
	//}
	return 0;
}
