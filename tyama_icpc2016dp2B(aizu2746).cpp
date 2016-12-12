#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string line;
	for(;cin>>line,line!="#";){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		vector<string>v;
		string s;
		for(auto e:line){
			if(e=='/')v.push_back(s),s="";
			else if(e=='b')s+=e;
			else s+=string(e-'0','.');
		}
		v.push_back(s);
		swap(v[a][b],v[c][d]);
		for(int i=0;i<v.size();i++){
			int c=0;
			for(auto e:v[i]){
				if(e=='b'){
					if(c)cout<<c;
					cout<<e;
					c=0;
				}else{
					c++;
				}
			}
			if(c)cout<<c;
			cout<<(i<v.size()-1 ? '/' : '\n');
		}
	}
}