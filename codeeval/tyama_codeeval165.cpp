#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
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
	string line;
	vector<string>names;
	unordered_map<string,int>required_num;
	unordered_map<string,unordered_set<string>>activity_already;
	unordered_map<string,unordered_map<string,int>>activity_num;
	for(;getline(cin,line);){
		vector<string>a=split(line,":");
		names.push_back(a[0]);
		vector<string>friends=split(a[1],",");
		required_num[a[0]]=(friends.size()+1)/2;
		vector<string>activities=split(a[2],",");
		for(auto &activity:activities){
			activity_already[a[0]].insert(activity);
			for(auto &_friend:friends)
				activity_num[_friend][activity]++;
		}
	}
	sort(names.begin(),names.end());
	for(auto &name:names){
		vector<string>activity_list;
		for(auto &activity:activity_num[name])
			if(activity.second>=required_num[name] && activity_already[name].find(activity.first)==activity_already[name].end())
				activity_list.push_back(activity.first);
		if(!activity_list.empty()){
			sort(activity_list.begin(),activity_list.end());
			cout<<name<<":";
			for(int i=0;i<activity_list.size();i++){
				if(i)cout<<",";
				cout<<activity_list[i];
			}
			cout<<endl;
		}
	}
}