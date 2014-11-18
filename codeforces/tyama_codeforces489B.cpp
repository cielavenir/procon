#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int cN,cM,n,m,r=0;
	scanf("%d",&cN);
	vector<int>N(cN);
	for(n=0;n<cN;n++)scanf("%d",&N[n]);
	sort(N.begin(),N.end());
	scanf("%d",&cM);
	vector<int>M(cM);
	for(m=0;m<cM;m++)scanf("%d",&M[m]);
	sort(M.begin(),M.end());

	for(n=m=0;;){
		for(;n<cN&&N[n]<M[m]-1;)n++;
		if(n>=cN)break;
		for(;m<cM&&N[n]-1>M[m];)m++;
		if(m>=cM)break;
		if(abs(N[n]-M[m])<=1){
			r++;
			n++;
			m++;
			if(n>=cN||m>=cM)break;
		}
	}
	printf("%d\n",r);
	return 0;
}