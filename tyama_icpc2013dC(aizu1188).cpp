#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;
char str[99999];
int parse(int i){
	if('0'<=str[i]&&str[i]<='9')return strtol(str+i,NULL,10)/2+1;
	assert(str[i]=='[');
	vector<int>v;
	int j=i,c=0;
	for(;;j++){
		if(str[j]=='[')if(++c==1)v.push_back(parse(j+1));
		if(str[j]==']')if(--c==-1)break;
	}
	sort(v.begin(),v.end());
	for(c=j=0;j<=v.size()/2;j++)c+=v[j];
	return c;
}
main(){
	int T;
	for(scanf("%d",&T);T--;printf("%d\n",parse(1)))scanf("%s",str);
}