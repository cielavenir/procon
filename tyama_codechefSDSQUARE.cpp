#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char s[19];
int main(){
	long long i,x,y;
	int j,r;
	set<long long>v;
	for(i=0;i<100001;i++){
		sprintf(s,"%lld",i*i);
		for(j=0;j<strlen(s);j++){
			if(s[j]!='0'&&s[j]!='1'&&s[j]!='4'&&s[j]!='9')break;
		}
		if(j==strlen(s))v.insert(i*i);
	}
	for(scanf("%d",&j);j--;){
		scanf("%lld%lld",&x,&y);
		set<long long>::iterator X=v.lower_bound(x),Y=v.upper_bound(y);
		printf("%d\n",distance(X,Y));
	}
}