#include <cstdio>
#include <queue>
enum{W=17,Z=100};
main(){
	std::queue<int>q;
	std::vector<int>r,sheet(W);
	int t=0,i,j,l;
	for(;r.size()<Z;t++){
		if(t%5==0)q.push(t/5);
		for(i=0;i<W;i++)if(sheet[i])sheet[i]--;
		for(;!q.empty();q.pop()){
			l=q.front()%5==1 ? 5 : 2;
			for(i=0;i<=W-l;i++){
				for(j=0;j<l;j++)if(sheet[i+j])break;
				if(j==l)break;
			}
			if(i>W-l)break;
			for(j=0;j<l;j++)sheet[i+j]=17*(q.front()%2)+3*(q.front()%3)+19;
			r.push_back(t-q.front()*5);

		}
	}
	for(;~scanf("%d",&l);)printf("%d\n",r[l]);
}