#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void solve(){
	int H,W;
	cin>>H>>W;
	vector<string>v(H);
	map<char,int>sheets;
	map<char,pair<int,int>>ma;
	map<char,pair<int,int>>mi;
	for(int i=0;i<H;i++){
		cin>>v[i];
		for(int j=0;j<W;j++)if(v[i][j]!='.'){
			sheets[v[i][j]]++;
			if(ma.find(v[i][j])==ma.end())ma[v[i][j]]={i,j};
			if(mi.find(v[i][j])==mi.end())mi[v[i][j]]={i,j};
			ma[v[i][j]].first=max(ma[v[i][j]].first,i);
			ma[v[i][j]].second=max(ma[v[i][j]].second,j);
			mi[v[i][j]].first=min(mi[v[i][j]].first,i);
			mi[v[i][j]].second=min(mi[v[i][j]].second,j);
		}
	}
	for(;!sheets.empty();){
		bool f=false;
		for(auto &e:sheets){
			int hs=mi[e.first].first,ws=mi[e.first].second;
			int he=ma[e.first].first+1,we=ma[e.first].second+1;
			int h=hs,z=0;
			for(;h<he;h++){int w=ws;for(;w<we;w++){
				if(v[h][w]==e.first)z++;
				else if(v[h][w]-'0')break;
			}if(w<we)break;}
			if(h==he && z==e.second){
				for(int h=hs;h<he;h++)for(int w=ws;w<we;w++)v[h][w]='0';
				sheets.erase(e.first);
				f=true;break;
			}
		}
		if(!f)break;
	}
	cout<<(sheets.empty()?"SAFE":"SUSPICIOUS")<<endl;
}
int main(){int T;for(cin>>T;T--;)solve();}
