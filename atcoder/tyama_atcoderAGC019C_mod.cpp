#import<algorithm>
#import<vector>
#import<cstdio>
using namespace std;
int main(){
	int x1,y1,x2,y2,n,xf=1,yf=1,x,y;
	scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
	if(x1>x2)swap(x1,x2),xf=-1;
	if(y1>y2)swap(y1,y2),yf=-1;
	vector<pair<int,int>>v;
	for(;n--;)if(scanf("%d%d",&x,&y),x1<=x&&x<=x2&&y1<=y&&y<=y2)v.emplace_back(x*xf,y*yf);
	sort(v.begin(),v.end());
	vector<int>d(v.size(),1<<30);
	for(auto &e:v)n=e.second,*lower_bound(d.begin(),d.end(),n)=n;
	n=lower_bound(d.begin(),d.end(),1<<30)-d.begin();
	printf("%.9f\n",100.0*(x2-x1+y2-y1)-20*n+5*(n+(n>min(x2-x1,y2-y1)))*3.1415926536);
}
