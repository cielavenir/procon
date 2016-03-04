#include <set>
#include <cstdio>
using namespace std;
int main(){
	int n,x0,y0,x1,y1;
	for(scanf("%d",&n);n--;){
		scanf("%d%d",&x0,&y0);
		x1=(x0+99)/100;
		y1=(y0+29)/30;
		x0/=100;
		y0/=30;
		set<int>se;
		se.insert(y0*5+x0);
		se.insert(y0*5+x1);
		se.insert(y1*5+x0);
		se.insert(y1*5+x1);
		bool first=true;
		for(set<int>::iterator it=se.begin();it!=se.end();++it){
			if(!first)putchar(' ');
			first=false;
			printf("%d",*it);
		}
		puts("");
	}
}