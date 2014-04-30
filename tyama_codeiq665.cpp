#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int N;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
bool ok(int x,int y){return min(x,y)==gcd(x,y);}
bool frozen(vector<int> &v){ //全てのi,jについて、min(v[i],v[j])はmax(v[i],v[j])の約数
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++)if(!ok(v[i],v[j]))return false;
	}
	return true;
}
void output(vector<int> &v){
	for(int i=0;i<N;i++)printf("%d ",v[i]);
	puts("");
}
int m;
void dfs(vector<int> &v,int d){
	if(d>=m)return;
	if(frozen(v)){
		fprintf(stderr,"Found %d\n",d); //26
		fflush(stderr);
		m=d;
	}
	for(int i=2;i<N-1;i++){ //2は20の約数であるから無視して問題ない
		if(!d&&i>2)return;
		for(int j=i+1;j<N;j++){
			int g=gcd(v[i],v[j]);
			if(min(v[i],v[j])!=g){
				int x=v[i],y=v[j];
				v[i]=g,v[j]=x/g*y;
				dfs(v,d+1);
				v[i]=x,v[j]=y;
			}
		}
	}
}
int main(int argc, char **argv){
	if(argc<2){
		printf("give me array size\n");
		return 1;
	}
	N=strtol(argv[1],NULL,10);
	m=12; ///
	int i,j,n;
	vector<int>v(N);
	for(i=0;i<N;i++){
		v[i]=i+1;
	}
	dfs(v,0);
	printf("%d\n",m);
}