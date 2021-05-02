#include <stdio.h>
#include <stdlib.h>
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
	Hpthread=LoadLibraryA("/lib/x86_64-linux-gnu/libpthread.so.0");
	mypthread_create=(type_pthread_create)GetProcAddress(Hpthread,"pthread_create");
	mypthread_join=(type_pthread_join)GetProcAddress(Hpthread,"pthread_join");
	mypthread_detach=(type_pthread_detach)GetProcAddress(Hpthread,"pthread_detach");
	mypthread_exit=(type_pthread_exit)GetProcAddress(Hpthread,"pthread_exit");
}

#define S(n)(n)*(n)
int x[2000],y[2000],tbl[2000][2000];
typedef struct{
	int i;
	int r0;
	int r1;
	int r2;
} tR;

tR* process(tR* R){
	R->r0=0;R->r1=0;R->r2=0;
	int i=R->i,j,k;
	for(j=0;j<i;j++)for(k=0;k<j;k++){
		int a=tbl[i][j],b=tbl[j][k],c=tbl[i][k],m=a;
		if(m<b)m=b;
		if(m<c)m=c;
		m=a+b+c-m-m;
		R->r0+=m>0;
		R->r1+=m==0;
		R->r2+=m<0;
	}
	return R;
}

int main(){
	int N,i,j,k,r0=0,r1=0,r2=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d%d",&x[i],&y[i]);
	for(i=0;i<N;i++)for(j=0;j<i;j++)tbl[i][j]=S(x[i]-x[j])+S(y[i]-y[j]);

	int nthreads=2;
	pthread_t *threads=(pthread_t*)alloca(sizeof(pthread_t)*nthreads);
	for(i=0;i<N;i+=nthreads){
		tR *Rmain;
		int i0=0;
		for(;i0<nthreads;i0++){
			if(i+i0>=N)break;
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
			r0+=R->r0;
			r1+=R->r1;
			r2+=R->r2;
			free(R);
		}
	}
	printf("%d %d %d\n",r0,r1,r2);
	return 0;
}
