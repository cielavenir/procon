#include <vector>
#include <set>
#include <string>
#include <cstdio>
using namespace std;
vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}
main(){
	set<int>s;
	int T,t=0,n,i,r;
	for(i=0;i<39999;i++)s.insert(i*i);
	for(scanf("%d",&T);t<T;t++){
		scanf("%d",&n);
		for(r=i=0;n/2>=i*i;i++)r+=s.find(n-i*i)!=s.end();
		printf("%d\n",r);
	}
}