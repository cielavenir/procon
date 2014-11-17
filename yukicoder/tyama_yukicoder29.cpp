#include <map>
#include <cstdio>
int main(){
	std::map<int,int>se;
	int i=0,n,x,c=0,r=0;
	for(scanf("%d",&n);i<3*n;i++)scanf("%d",&x),se[x]++;
	for(std::map<int,int>::iterator it=se.begin();it!=se.end();++it)r+=it->second/2,c+=it->second%2;
	printf("%d\n",r+c/4);
}