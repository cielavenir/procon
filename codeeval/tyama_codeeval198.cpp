#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int solve(int C,int D,int V,set<int> &P){
	for(;;){
		long long total=0;
		for(auto it=P.begin();;){
			total+=*it*(long long)C;
			if(++it==P.end()||total+1<*it)break;
		}
		if(total+1>V)break;
		P.insert(total+1);
	}
	return P.size()-D;
}

#ifdef CODEJAM
int main(){
	int T,t=0;
	for(cin>>T;t<T;){
		int C,D,V,_;
		cin>>C>>D>>V;
		set<int>P;
		for(int i=0;i<D;i++)cin>>_,P.insert(_);
		if(*P.begin()!=1)P.insert(1);
		printf("Case #%d: %d\n",++t,solve(C,D,V,P));
	}
}
#else
int main(){
	string line,s;
	for(;getline(cin,line);){
		int C,D,V;
		istringstream ss(line);
		ss>>C>>s>>V>>s;
		set<int>P;
		for(;ss>>D;)P.insert(D);
		D=P.size();
		if(*P.begin()!=1)P.insert(1);
		printf("%d\n",solve(C,D,V,P));
	}
}
#endif