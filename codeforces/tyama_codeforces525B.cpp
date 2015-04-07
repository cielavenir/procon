#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string s;
	cin>>s;
	vector<int>v((s.size()+1)/2);
	int N;
	for(cin>>N;N--;){
		int x;
		cin>>x;
		v[x-1]++;
	}
	for(int i=1;i<v.size();i++)v[i]+=v[i-1];
	for(int i=0;i<v.size();i++)if(v[i]%2)swap(s[i],s[s.size()-i-1]);
	cout<<s<<endl;
}