#include <vector>
#include <cstdio>
int main(){
	int T,n,m,e,i;
	scanf("%d%d",&T,&n);
	std::vector<int>a(n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	//greedy
	i=-1;
	for(scanf("%d",&m);m;m--){
		scanf("%d",&e);
		for(i++;i<n;i++){
			if(e-a[i]<0)i=n;
			if(e-a[i]<=T)break;
		}
		if(i>=n)break;
	}
	puts(m?"no":"yes");
}