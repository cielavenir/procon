#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int calc(const vector<int> &v){
	vector<pair<int,int> > srt(v.size());
	for(int i=0;i<v.size();i++)srt[i]=make_pair(-v[i],i);
	sort(srt.begin(),srt.end());
	int rank=1,cur=srt[0].first;
	for(int i=0;i<srt.size();i++){
		if(cur<srt[i].first)rank++,cur=srt[i].first;
		if(srt[i].second==0)return rank;
	}
	abort();
}
int main(){
	int n;
	string s;
	vector<pair<int,int> >match;
	cin>>n;
	vector<int>win(n);
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=i+1;j<n;j++){
			if(s[j]=='o')win[i]++;
			else if(s[j]=='x')win[j]++;
			else if(s[j]=='-')match.push_back(make_pair(i,j));
		}
	}
	int result=n;
	if(match.empty())result=calc(win);
	for(int i=0;i<1<<match.size();i++){
		for(int j=0;j<match.size();j++){
			if(i&(1<<j))win[match[j].first]++;
			else win[match[j].second]++;
		}
		result=min(result,calc(win));
		for(int j=0;j<match.size();j++){
			if(i&(1<<j))win[match[j].first]--;
			else win[match[j].second]--;
		}
	}
	cout<<result<<endl;
}