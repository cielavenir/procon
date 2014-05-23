#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<pair<string,long long> >costs;
	vector<pair<map<string,int>,int> >votes;
	//vector<pair<vector<int>,int> >votes;
	int issues;

	int result_issues;
	long long result_cost=0;
	int result=0;
	{
		string s;
		getline(cin,s);
		vector<string> a=split(s,":");
		issues=strtol(a[1].substr(1).c_str(),NULL,10);
		result_issues=issues+1;
		getline(cin,s);
		for(int i=0;i<issues;i++){
			getline(cin,s);
			a=split(s,":");
			long long cost=strtoll(a[1].substr(1).c_str(),NULL,10);
			result_cost+=cost;
			costs.push_back(make_pair(a[0],cost));
		}
		for(;;){
			s="";
			getline(cin,s);
			getline(cin,s); //Area
			getline(cin,s); //Voices
			if(s=="")break;
			map<string,int>m;
			//vector<int>m;
			int people=0;
			for(int i=0;i<issues;i++){
				getline(cin,s);
				a=split(s,":");
				int n=strtol(a[1].substr(1).c_str(),NULL,10);
				m[a[0]]=n;
				//m.push_back(n);
				people+=n;
			}
			votes.push_back(make_pair(m,people));
		}
	}
	for(int i=0;i<1<<issues;i++){
		long long cost=0;
		int ncost=0;
		int ok=0;
		for(int j=0;j<issues;j++)if(i&1<<j){
			cost+=costs[j].second;
			ncost++;
		}
		if(ncost>result_issues || (ncost==result_issues&&cost>result_cost))continue;
		for(int k=0;k<votes.size();k++){
			int people=0;
			for(int j=0;j<issues;j++)if(i&(1<<j)){
				people+=votes[k].first[costs[j].first];
			}
			if(people*2>votes[k].second)ok+=votes[k].second;
		}
		if(ok>=270){
			result_issues=ncost;
			result_cost=cost;
			result=i;
		}
	}
	vector<string>z;
	for(int j=0;j<issues;j++)if(result&(1<<j)){
		z.push_back(costs[j].first);
	}
	sort(z.begin(),z.end());
	for(int i=0;i<z.size();i++)cout<<z[i]<<endl;
}