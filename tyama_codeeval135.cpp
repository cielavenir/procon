//based on codeiq408

#include <iostream>
#include <string>
#include <vector>
//#include <unordered_map>
#include <map>
#include <algorithm>
#include <cstdlib>
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

map<string,vector<string> >m;
//vector<string> lst_max;
int i_max=0;
void dfs(vector<string>&lst,map<string,int> &visit,string &cur) throw(int){
	vector<string>&v=m[cur];
	int i=0,j;
	for(;i<v.size();i++){
	//for(i=v.size()-1;i>=0;i--){
		if(!visit[v[i]]){
			lst.push_back(v[i]);
			visit[v[i]]=visit[cur]+1;
			dfs(lst,visit,v[i]);
			visit[v[i]]=0;
			lst.pop_back();
		}
	}
	if(lst.size()>i_max){
		//cout<<lst.size()<<endl;
		i_max=lst.size();//,lst_max=lst;
	}
}

int main(int argc, char **argv){
	int i,j;
	vector<string>v;
	string line;
	for(;getline(cin,line);){
		m.clear();
		//lst_max.clear();
		i_max=0;
		vector<string>v=split(line,",");
		for(i=0;i<v.size();i++)for(j=0;j<v.size();j++){
			if(v[i][v[i].size()-1]==v[j][0]){
				m[v[i]].push_back(v[j]);
				//m[v[j]].push_back(v[i]);
			}
		}
		for(i=0;i<v.size();i++){
			//cout<<"*** "<<i<<endl;
			vector<string>lst;
			lst.push_back(v[i]);
			map<string,int>visit;
			visit[v[i]]=1;
			dfs(lst,visit,v[i]);
		}
		if(i_max>1)cout<<i_max<<endl;
		else cout<<"None"<<endl;
		//reverse(lst_max.begin(),lst_max.end());
		//cout<<lst_max.size()<<endl;
		//for(i=0;i<lst_max.size();i++)cout<<lst_max[i]<<endl;
	}
}