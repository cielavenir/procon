#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
	int N,p,a,b,c,d,e,f,s,m;
	char l[99];
	for(;scanf("%d",&N),N;puts("#")){
		vector<pair<double,string> >v;
		for(;N--;){
			scanf("%s%d%d%d%d%d%d%d%d%d",l,&p,&a,&b,&c,&d,&e,&f,&s,&m);
			a+=b+c,b=(d+e)*m,c=f*s*m;
			v.push_back(make_pair(-1.0*(c-p)/(a+b),l));
		}
		sort(v.begin(),v.end());
		for(N=0;N<v.size();N++)printf("%s\n",v[N].second.c_str());
	}
}