#include <string>
#include "inspect.hpp"
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int rev(int n){
	string s=to_string(n);
	reverse(s.begin(),s.end());
	return strtol(s.c_str(),NULL,10);
}
pair<int,int> f1(pair<int,int> &xy){
	return xy.first<xy.second ? make_pair(rev(xy.first),xy.second) : make_pair(xy.first,rev(xy.second));
}
pair<int,int> f2(pair<int,int> &xy){
	return xy.first<xy.second ? make_pair(xy.first,xy.second-xy.first) : make_pair(xy.first-xy.second,xy.second);
}

int main(){
	int n__,m__;
	scanf("%d%d",&n__,&m__);
	set<pair<int,int>>ok,ng;
	int r=0;
	for(int n_=1;n_<=n__;n_++)for(int m_=1;m_<=m__;m_++){
		int n=n_;
		int m=m_;
		if(ok.find({n,m})!=ok.end()){
			r++;
			continue;
		}
		if(ng.find({n,m})!=ng.end()){
			continue;
		}
		printf("%d %d\n",n,m);
		set<pair<int,int>>se;
		pair<int,int>cur={n,m};
		se.insert(cur);
		int k=0;
		for(;cur.first&&cur.second;k++){
			cur=f1(cur);
			cur=f2(cur);
			if(se.find(cur)!=se.end())break;
			se.insert(cur);
			//printf("%d %d\n",cur.first,cur.second);
		}
		if(cur.first&&cur.second){
			r++;
			for(auto &e:se)ok.insert(e);
		}
		if(!cur.first||!cur.second){
			for(auto &e:se)ng.insert(e);
		}
	}
	printf("%d\n",r);
}
