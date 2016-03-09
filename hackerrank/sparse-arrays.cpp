#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	vector<string> v(N);
	for(int i=0;i<N;i++)cin>>v[i];
	sort(v.begin(),v.end());
	cin>>N;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		auto it1=lower_bound(v.begin(),v.end(),s);
		auto it2=upper_bound(v.begin(),v.end(),s);
		printf("%d\n",it2-it1);
	}
}