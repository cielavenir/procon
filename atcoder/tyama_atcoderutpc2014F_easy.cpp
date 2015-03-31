#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
	unordered_map<string,int> m;
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		string s;
		cin>>s;
		if(m.find(s)!=m.end()){
			cout<<m[s]<<'\n';
		}else{
			int i;
			vector<int>v(s.size());
			for(i=0;i<s.size()-1;i++)if(s[i]!=s[i+1]){
				swap(s[i],s[i+1]);
				if(m.find(s)!=m.end())v[m[s]]=1;
				swap(s[i],s[i+1]);
			}
			for(i=0;v[i];i++);
			cout<<(m[s]=i)<<'\n';
		}
	}
}