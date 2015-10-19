#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;

namespace std{
	template<typename I>
	class hash<pair<I,I>>{
		public:
		size_t operator()(const pair<I,I> &p) const {return hash<long long>() (((long long)(p.first))<<32|p.second);}
	};
}

int checkio(const vector<pii> &lines_list){
	int M=5;
	unordered_set<pii> se;
	for(auto &e:lines_list)se.emplace(min(e.first,e.second)-1,max(e.first,e.second)-1);
	int r=0;
	for(int k=1;k<M;k++)for(int x=0;x<(M-1)-k+1;x++)for(int y=0;y<(M-1)-k+1;y++){
		vector<int>v(k);
		iota(v.begin(),v.end(),0);
		if(all_of(v.begin(),v.end(),[&](int i)->bool{
			return se.find({(y+i)*M+x,(y+i+1)*M+x})!=se.end() &&
				se.find({y*M+x+i,y*M+x+i+1})!=se.end() &&
				se.find({(y+i)*M+x+k,(y+i+1)*M+x+k})!=se.end() &&
				se.find({(y+k)*M+x+i,(y+k)*M+x+i+1})!=se.end();
		}))r++;
	}
	return r;
}

int main(){
	string line,s;
	for(;getline(cin,line);){
		vector<pii> list;
		{
			istringstream ss(line);
			int x,y;
			for(;ss>>x>>y;ss>>s)list.emplace_back(x,y);
		}
		printf("%d\n",checkio(list));
	}
}