#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string T;
	int N;
	unordered_map<char,int>m={{0,-1}};
	cin>>T>>N;
	for(int i=0;i<T.size();i++){
		m[T[i]]=i;
		m[T[i]-32]=i+T.size();
	}
	vector<string>v(N);
	for(int i=0;i<N;i++)cin>>v[i];
	sort(v.begin(),v.end(),[&](const string &a,const string &b){
		for(int i=0;i<=min(a.size(),b.size());i++){
			if(m[a[i]]<m[b[i]])return true;
			if(m[a[i]]>m[b[i]])return false;
		}
		return false;
	});
	for(int i=0;i<N;i++)cout<<v[i]<<endl;
}