#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct SAComp{
	const int h,*g;
	SAComp(const int h, const int* g) : h(h), g(g) {}
	bool operator()(const int a, const int b){
		return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a+h] < g[b+h];
	}
};
vector<int> buildSA(string &t){
	int n=t.size();
	int g[n],b[n];
	vector<int>suff(n);
	for(int i=0;i<n;i++)suff[i]=i,g[i]=t[i];
	b[0]=b[n-1]=0;
	sort(suff.begin(),suff.end(),SAComp(0,g));
	for(int h=1;b[n-1]!=n-1;h<<=1){
		SAComp comp(h,g);
		sort(suff.begin(),suff.end(),comp);
		for(int i=0;i<n-1;i++)b[i+1]=b[i]+comp(suff[i],suff[i+1]);
		for(int i=0;i<n;i++)g[suff[i]]=b[i];
	}
	return suff;
}
string buildBWT(string &t,vector<int> &suff){
	int n=t.size();
	string bw;
	for(int i=0;i<n;i++)bw+=t[(suff[i]?:n)-1];
	return bw;
}

int main(){
	int N,D=1,d,r,i,j;
	string str,s;
	cin.tie(0);
	ios::sync_with_stdio(false);
	for(cin>>N;N--;){
		cin>>str;str+='$';
		vector<int>suff=buildSA(str);
		str=buildBWT(str,suff);

		vector<pair<char,int> >v(str.size()),sorted(str.size());
		for(i=0;i<str.size();i++)v[i]=sorted[i]=make_pair(str[i],i);
		sort(sorted.begin(),sorted.end());
		vector<int>rev(str.size());
		for(i=0;i<str.size();i++)rev[sorted[i].second]=i;
		vector<int>ret;

		cin>>s;
		reverse(s.begin(),s.end());
		for(r=i=0;i<str.size();i++){
			auto cur=v[i];
			if(cur.first=='$')continue;
			d=cur.first!=s[0];
			for(j=1;j<s.size();j++){
				//auto it=find(sorted.begin(),sorted.end(),cur);
				//cur=v[it-sorted.begin()];
				cur=v[rev[cur.second]];
				if(cur.first=='$')break;
				if(cur.first!=s[j]){
					if(++d>D)break;
				}
			}
			if(j==s.size())ret.push_back(suff[cur.second]-1); // -1 means first '$'
		}
		sort(ret.begin(),ret.end());
		for(i=0;i<ret.size();i++)cout<<ret[i]<<(i<ret.size()-1?" ":"");
		cout<<endl;
	}
}