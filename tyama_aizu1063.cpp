#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int n,i,r,last,time,day;
	for(;cin>>n,n;){
		vector<pair<int,string> >program;
		set<string>fav;
		{
			string s;
			map<string,int>m;
			for(;n--;){
				cin>>s>>day>>time;
				program.push_back(make_pair(time=day*1440+time/100*60+time%100,s));
				m[s]=time;
			}
			vector<int>v;
			for(cin>>n;n--;v.push_back(m[s]),fav.insert(s))cin>>s;
			sort(v.begin(),v.end());
			for(i=0;i<v.size()-1;i++)if(v[i+1]-v[i]<30){puts("-1");goto next;}
		}
		sort(program.begin(),program.end());
		for(last=r=i=0;i<program.size();i++){
			if(program[i].first>=last){
				last=program[i].first+30;
				r++;
			}else if(fav.find(program[i].second)!=fav.end()){
				last=program[i].first+30;
			}
		}
		printf("%d\n",r);
		next:;
	}
}