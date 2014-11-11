#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
using namespace std;
char buf[99];
int main(){
	int N,K;
	cin>>N>>K;
	unordered_map<string,set<long long>>c;
	set<long long>r;
	for(long long i=1;i<N-1;i++){
		sprintf(buf,"%lld",i*i*i);
		string k(buf);
		sort(k.begin(),k.end());
		c[k].insert(i*i*i);
		if(c[k].size()==K)
			r.insert(*c[k].begin());
		else if(c[k].size()>K)
			r.erase(*c[k].begin());
	}
	for(auto &e:r)cout<<e<<endl;
}