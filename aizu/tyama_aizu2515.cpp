#include <cstdio>
#include <vector>
#include <string>
using namespace std;
char s[99];
main(){
	vector<pair<string,int> >v;
	int n,t,t1,t2,x,y;
	scanf("%d%d",&n,&t);
	scanf("%d:%d %s",&x,&y,s);
	for(n--;n--;){
		scanf("%d:%d %s",&x,&y,s);t1=x*60+y;
		scanf("%d:%d %s",&x,&y,s);t2=x*60+y;
		if(t2-t1>=t)v.push_back(make_pair(s,t2-t1));
	}
	printf("%d\n",v.size());
	for(n=0;n<v.size();n++)printf("%s %d\n",v[n].first.c_str(),v[n].second);
}