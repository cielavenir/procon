#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;
int s;
vector<int>p;
int d(vector<int>&v){
	int q[2]={s-v[v.size()-1],v[v.size()-1]},i=0,j;
	for(;i<2;i++){
		vector<int>a;
		vector<int>b;
		for(j=0;j<p.size();j++)b.push_back(abs(p[j]-q[i]));
		sort(b.begin(),b.end(),greater<int>());
		for(j=0;j<v.size();j++){
			if(!b.empty()&&v[j]==b[b.size()-1])b.erase(b.begin()+b.size()-1);
			else a.push_back(v[j]);
		}
		if(b.empty()){
			p.push_back(q[i]);
			if(a.empty()||d(a))return 1;
			p.erase(p.begin()+p.size()-1);
		}
	}
	return 0;
}
int main(){
	int x;
	vector<int>v;
	for(;~scanf("%d",&x);)if(x>0)v.push_back(x);
	sort(v.begin(),v.end());
	p.push_back(0);
	p.push_back(s=v[v.size()-1]);
	v.erase(v.begin()+v.size()-1);
	d(v);
	sort(p.begin(),p.end());
	for(x=0;x<p.size();x++){
		if(x)putchar(' ');
		printf("%d",p[x]);
	}
	puts("");
}