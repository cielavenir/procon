#include <set>
#include <cstdio>
int main(){
	int T,a,b;
	std::set<int>se;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&a,&b);
		if(a==1)se.insert(b);
		if(a==2)se.erase(b);
		if(a==3)puts(se.find(b)!=se.end()?"Yes":"No");
	}
}