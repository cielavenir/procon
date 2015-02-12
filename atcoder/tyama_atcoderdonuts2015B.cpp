#include <vector>
#include <cstdio>
using namespace std;
int chk(int n){
	int c=0;
	for(;n;n>>=1)c+=n&1;
	return c>=3;
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int>base(N);
	vector<pair<int,int> >bonus(M);
	for(int i=0;i<N;i++)scanf("%d",&base[i]);
	for(int i=0;i<M;i++){
		int point,num,val=0,t;
		scanf("%d%d",&point,&num);
		for(int j=0;j<num;j++){
			scanf("%d",&t);
			val|=1<<(t-1);
		}
		bonus[i]=make_pair(point,val);
	}
	int ret=0;
	for(int i=0;i<1<<N;i++){
		int selected=0,total=0,val=0;
		for(int j=0;j<N;j++)if(i&(1<<j)){
			selected++;
			total+=base[j];
			val|=1<<j;
		}
		if(selected==9){
			for(int j=0;j<M;j++)if(chk(val&bonus[j].second))total+=bonus[j].first;
			if(ret<total)ret=total;
		}
	}
	printf("%d\n",ret);
}