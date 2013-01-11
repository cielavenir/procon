#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int s[14];
int main(){
	int a,b,c,d,e;
	for(;~scanf("%d,%d,%d,%d,%d",&a,&b,&c,&d,&e);){
		map<int,int>m;
		memset(s,0,sizeof(s));
		m[a]++,m[b]++,m[c]++,m[d]++,m[e]++;
		s[a]=1,s[b]=1,s[c]=1,s[d]=1,s[e]=1;
		vector<int>v;
		for(a=1;a<=9;a++)if(s[a]&&s[a+1]&&s[a+2]&&s[a+3]&&s[a+4]){puts("straight");goto n;}
		if(s[a]&&s[a+1]&&s[a+2]&&s[a+3]&&s[1]){puts("straight");goto n;}
		for(a=1;a<=13;a++)v.push_back(m[a]);
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		if(v[0]==4)puts("four card");
		else if(v[0]==3)puts(v[1]==2?"full house":"three card");
		else if(v[0]==2)puts(v[1]==2?"two pair":"one pair");
		else puts("null");
		n:;
	}
}