#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef pair<int,int> pii;

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
	vector<pair<
		pair<vector<pii>,string>,
		pii
	> >v;
	string line;
	//v.first.first==vector
	//v.first.second==agent name
	//v.second.first==entered time
	//v.second.second==exit time
	for(;getline(cin,line);){
		vector<string>a=split(line," ");
		string agent=a[0];
		vector<pii>_v;
		int h,m,s;
		sscanf(a[1].c_str(),"%02d:%02d:%02d",&h,&m,&s);
		int t=h*3600+m*60+s;
		for(h=2;h<a.size();h+=2){
			_v.push_back(make_pair(strtol(a[h].c_str(),NULL,10),strtol(a[h+1].c_str(),NULL,10)));
		}
		v.push_back(make_pair(make_pair(_v,agent),make_pair(t,t)));
	}

	//must implement priority queue properly here.
	for(int i=0;i<v.size();i++){
		int room=100;
		for(int j=0;j<v[i].first.first.size();j++){
			int nextroom=v[i].first.first[j].first;
			if(nextroom/100!=room/100)
				v[i].second.second+=20+abs(nextroom/100-room/100)*10;
			else
				v[i].second.second+=10;
			v[i].second.second+=v[i].first.first[j].second;
			room=nextroom;
		}
		int nextroom=100;
		if(nextroom/100!=room/100)
			v[i].second.second+=20+abs(nextroom/100-room/100)*10;
		else
			v[i].second.second+=10;
		v[i].second.second+=i*5; //fake... fake...
		printf("%02d:%02d:%02d %02d:%02d:%02d\n",
			v[i].second.first/3600,v[i].second.first/60%60,v[i].second.first%60,
			v[i].second.second/3600,v[i].second.second/60%60,v[i].second.second%60);
	}
}