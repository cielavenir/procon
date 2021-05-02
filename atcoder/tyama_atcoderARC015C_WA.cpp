#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long,string> pls;
map<string,vector<pls> >m;
map<pair<string,string>,pls>memo;
long long M_max=1;
pair<string,string> p_max;
const pls dfs(const string &s,vector<string>&_v) throw(int){
	if(find(_v.begin(),_v.end(),s)!=_v.end()){
		//throw -1;
		return make_pair(1,s);
	}else if(m.find(s)==m.end()){
		return make_pair(1,s);
	}else{
		vector<pls>&v=m[s];
		pls M_max_dfs;
		for(int i=0;i<v.size();i++){
			pair<string,string> p=make_pair(s,v[i].second);
			pls M;
			if(memo.find(p)!=memo.end()){
				M=memo[p];
			}else{
				_v.push_back(s);
				M=dfs(v[i].second,_v);
				_v.pop_back();
				//if(M.first==-1)continue;
				M.first*=v[i].first;
				memo[p]=M;
			}
			if(M.first>M_max_dfs.first){
				M_max_dfs=M;
			}
		}
		return M_max_dfs;
	}
}
int main(){
	long long n,u;
	string sl,ss;
	cin>>n;
	for(;n;n--){
		cin>>sl>>u>>ss;
		if(u==1){
			p_max=make_pair(sl,ss);
		}else{
			m[sl].push_back(make_pair(u,ss));
		}
	}
	map<string,vector<pls> >::iterator it=m.begin();
	for(;it!=m.end();it++){
		vector<string>v;
		try{
			pls M=dfs(it->first,v);
			if(M.first>M_max){
				M_max=M.first;
				p_max=make_pair(it->first,M.second);
			}
		}catch(int e){}
	}
	cout<<1<<p_max.first<<"="<<M_max<<p_max.second<<endl;
}