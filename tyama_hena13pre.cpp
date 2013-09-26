//http://nabetani.sakura.ne.jp/hena/ord13updowndouble/
//http://qiita.com/Nabetani/items/89fb0e2e712d4b396535
#include <queue>
#include <map>
#include <cstdio>
using namespace std;
int main(){
	int n;
	map<int,int>back;
	back[0]=0;
	back[1]=0;
	map<int,int>count;
	count[0]=0;
	count[1]=1;
	queue<int>q;
	q.push(1);
	for(;!q.empty();){
		int x=q.front();q.pop();
		int a[3]={x-1,x+1,x*2};
		for(int i=0;i<3;i++){
			if(a[i]<500000&&count.find(a[i])==count.end()){
				back[a[i]]=x;
				count[a[i]]=count[x]+1;
				q.push(a[i]);
			}
		}
	}
	for(;~scanf("%d",&n);){
		printf("%d\n",count[n]);fflush(stdout);
	}
	return 0;
}