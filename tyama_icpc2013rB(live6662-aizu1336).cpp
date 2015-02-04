#include <vector>
#include <cstdio>
int main(){
	int N,L;
	for(;scanf("%d%d",&N,&L),L;){
		std::vector<std::pair<int,int> >v(N);
		for(int i=0;i<N;i++){
			char c;
			scanf(" %c%d",&c,&v[i].second);
			v[i].first=c=='L'?-1:1;
		}
		int rl,rr,f=1,t=0;
		for(;f;t++){
			rl=rr=f=0;
			for(int i=0;i<N;i++)if(v[i].second!=0&&v[i].second!=L){
				v[i].second+=v[i].first;
				if(v[i].second==0)rl=i+1;
				if(v[i].second==L)rr=i+1;
			}
			for(int i=0;i<N;i++)if(v[i].second!=0&&v[i].second!=L){
				f=1;
				for(int j=i+1;j<N;j++)if(v[i].second==v[j].second){
					v[i].first*=-1;
					v[j].first*=-1;
				}
			}
		}
		printf("%d %d\n",t,rl?rl:rr);
	}
}