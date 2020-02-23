/// uh-oh, they limited the judge core to 1 :( ///

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

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

typedef int (*type_pthread_create)(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void * arg);
typedef int (*type_pthread_join)(pthread_t th, void **thread_return);
typedef int (*type_pthread_detach)(pthread_t th);
typedef void (*type_pthread_exit)(void *retval);
static void* Hpthread;
static type_pthread_create mypthread_create;
static type_pthread_join mypthread_join;
static type_pthread_detach mypthread_detach;
static type_pthread_exit mypthread_exit;
int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void * arg){
	return mypthread_create(thread,attr,start_routine,arg);
}
int pthread_join(pthread_t th, void **thread_return){
	return mypthread_join(th,thread_return);
}
int pthread_detach(pthread_t th){
	return mypthread_detach(th);
}
void pthread_exit(void *retval){
	mypthread_exit(retval);
}
__attribute__((constructor)) static void initpthread(){
	//Hpthread=LoadLibraryA("/usr/lib/libpthread.dylib");
	//Hpthread=LoadLibraryA("/usr/lib64/libpthread.so.0");
	Hpthread=LoadLibraryA("/lib64/libpthread.so.0");
	mypthread_create=(type_pthread_create)GetProcAddress(Hpthread,"pthread_create");
	mypthread_join=(type_pthread_join)GetProcAddress(Hpthread,"pthread_join");
	mypthread_detach=(type_pthread_detach)GetProcAddress(Hpthread,"pthread_detach");
	mypthread_exit=(type_pthread_exit)GetProcAddress(Hpthread,"pthread_exit");
}

typedef __int128_t T;
bool F(T d,T e,T f,T g,T h,T i,T m,T n){
	return (f-d)*(n-e)*(f=(h-f)*(n-g)-(m-f)*(i-g))>f*(m-d)*(g-e)&f*(d-h)*(n-i)>f*(m-h)*(e-i);
}
int X[4000],Y[4000];
typedef struct{
	int i;
	long long R;
}tR;
tR* process(tR* R){
	//R->R=0;
	int i=R->i;
	long long r=0;
	for(int j=0;j<i;j++)for(int k=0;k<j;k++){
		if(F(X[i],Y[i],X[j],Y[j],X[k],Y[k],0,0))r++;
	}
	R->R=r;
	return R;
}

int main(){
	long long r=0;
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",X+i,Y+i);

	int nthreads=12;
	pthread_t *threads=(pthread_t*)malloc(sizeof(pthread_t)*nthreads);
	for(int i=0;i<n;i+=nthreads){
		tR *Rmain;
		int i0=0;
		for(;i0<nthreads;i0++){
			if(i+i0>=n)break;
			tR *R=malloc(sizeof(tR));
			R->i=i+i0;
			if(i0<nthreads-1){
				pthread_create(&threads[i0],NULL,(void*(*)(void*))process,R);
			}else{
				Rmain=R;
				process(R);
			}
		}
		for(int i1=0;i1<i0;i1++){
			tR *R;
			if(i1<nthreads-1){
				pthread_join(threads[i1],(void**)&R);
			}else{
				R=Rmain;
			}
			r+=R->R;
			free(R);
		}
	}
	printf("%lld\n",r);
}
