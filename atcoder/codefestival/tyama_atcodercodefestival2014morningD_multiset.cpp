#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
int main(){
	int n,m,z;
	cin>>n>>m;
	vector<pii>person(n);
	multiset<int>pillows;
	for(int i=0;i<n;i++)cin>>person[i].first>>person[i].second;
	for(int i=0;i<m;i++)cin>>z,pillows.insert(z);
	sort(person.begin(),person.end(),[](const pii &a,const pii &b)->bool{
		return (a.second<b.second)||(a.second==b.second&&a.first<b.first);
	});
	int cur=0,ret=0;
	for(int i=0;i<n;i++){
		auto it1=pillows.lower_bound(person[i].first);
		if(it1==pillows.end())continue;
		if(*it1<person[i].first)it1++;
		if(*it1<=person[i].second){
			pillows.erase(it1);
			ret++;
		}
	}
	printf("%d\n",ret);
}
