#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

set<int> s;
map<int,vector<int> >m;

void solve(int key, int depth){
	if(!depth)return;
	s.insert(key);
	int i;
	vector<int> &z=m[key];
	for(i=0;i<z.size();i++)solve(z[i],depth-1);
}

main(){
	int n,i,x,y;
	for(;cin>>n>>n&&n;cout<<s.size()-1<<endl){
		m.clear();
		s.clear();
		for(i=0;i<n;i++){
			cin>>x>>y;
			m[x].push_back(y);
			m[y].push_back(x);
		}
		solve(1,3);
	}
}
