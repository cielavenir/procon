#include <map>
#include <cstdio>
int a[1000010];
int main(){
	int T,N,K,i,j;
	long long s,r;
	for(scanf("%d",&T);T--;){
		std::map<int,int>m;m[0]+=1;
		r=0;
		scanf("%d%d",&N,&K);
		for(i=1;i<=N;i++)scanf("%d",a+i);
		for(i=1;i<=N;i++){
			a[i]=(a[i]+a[i-1])%K;
			m[a[i]]++;
		}
		for(auto it=m.begin();it!=m.end();++it){
			r+=(long long)it->second*(it->second-1)/2;
		}
		printf("%lld\n",r);
	}
	return 0;
}