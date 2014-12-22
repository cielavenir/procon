//gcc -fopenmp -O3 tyama_codeiq432_openmp.c
//icc -openmp -fast tyama_codeiq432_openmp.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_max_threads() 1
#define omp_get_thread_num() 0
#endif

#if defined(WIN32) || (!defined(__GNUC__) && !defined(__clang__))
	#define LLU "%I64u"
#else
	#define LLU "%llu"
#endif

int v[999999];
int main(){
	int N=0,i,j;
	long long r=0;
	for(;~scanf("%d",v+N);N++);
#pragma omp parallel for reduction(+:r) private(i)
	for(j=0;j<N;j++){
		for(i=0;i<j;i++)if(v[i]>v[j])r++;
	}
	printf(LLU"\n",r);
}