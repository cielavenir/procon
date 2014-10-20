#include <queue>
#include <map>
#include <cstdio>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int>start(n),end1(n),end2(n);
	for(int i=0;i<n;i++)scanf("%d",&start[i]);
	{
		vector<int>p(m);
		for(int i=0;i<m;i++)scanf("%d",&p[i]);
		for(int i=0,c=0,x=0;i<m;i++,x^=1)for(int j=0;j<p[i];j++,c++)end1[c]=x;
		for(int i=0,c=0,x=1;i<m;i++,x^=1)for(int j=0;j<p[i];j++,c++)end2[c]=x;
	}
	map<vector<int>,int>depth;
	queue<vector<int> >q;
	depth[start]=1,depth[end1]=depth[end2]=-1;
	q.push(start),q.push(end1),q.push(end2);
	for(;!q.empty();){
		vector<int>cur=q.front();q.pop();
		int d=depth[cur];
		for(int i=0;i<n-1;i++)if(cur[i]!=cur[i+1]){
			swap(cur[i],cur[i+1]);
			map<vector<int>,int>::iterator it=depth.find(cur);
			if(it==depth.end()){
				depth[cur]=d+(d>0?1:-1);
				q.push(cur);
			}else if(it->second*d<0){
				d-=it->second;
				if(d<0)d=-d;
				printf("%d\n",d-1);
				return 0;
			}
			swap(cur[i],cur[i+1]);
		}
	}
	puts("0");
}