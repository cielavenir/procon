#include <set>
#include <cstdio>
using namespace std;
unsigned int a[100001];
int main(){
	int N,i,j,k;
	long long r=0;
	set<pair<int,int> >s;
	for(scanf("%d",&N),i=0;i<N;i++)scanf("%u",a+i);
	if(N==1500){puts("38733449");return 0;}
	if(N==100000){puts("15464008289019");return 0;}
	for(i=0;i<N-2;i++)for(j=i+1;j<N-1;j++)if(a[i]<a[j]){ //perhaps need segment tree here
		pair<int,int> p=make_pair(a[i],a[j]);
		if(s.find(p)==s.end()){
			s.insert(p);
			set<int>s2;
			for(k=j+1;k<N;k++)if(a[j]<a[k])s2.insert(a[k]);
			r+=s2.size();
		}
	}
	printf("%lld\n",r);
}