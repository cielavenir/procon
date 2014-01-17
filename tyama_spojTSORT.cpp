#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i=0,n;
	cin>>n;
	vector<int>v(n);
	for(;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	for(i=0;i<n;i++)cout<<v[i]<<"\n";
}