#include <vector>
#include <cstdio>
using namespace std;
void D(int n,vector<int>*v,int*b){
	b[n]=1;
	for(int i=0;i<v[n].size();i++)if(!b[v[n][i]])D(v[n][i],v,b);
}
main(){
	int m,n,i,j,next,d[259];
	for(;scanf("%d%d",&m,&n)>1;puts(i<=n+1?"NG":"OK")){
		d[0]=d[n+1]=0;
		for(i=1;i<=n;i++)scanf("%d",d+i);
		vector<int>vf[259],vr[259];
		for(i=0;i<=n;i++)for(j=1;j<=m;j++){
			next=i+j;
			if(next>n+1)next=n+1;
			next+=d[next];
			if(next>n+1)next=n+1;
			if(next<0)next=0;
			vf[i].push_back(next),vr[next].push_back(i);
		}
		int bf[259]={0},br[259]={0};
		D(0,vf,bf),D(n+1,vr,br);
		for(i=0;i<=n+1;i++)if(bf[i]&&!br[i])break;
	}
}