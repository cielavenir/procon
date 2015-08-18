#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	string line,s;
	for(;getline(cin,line);){
		vector<vector<int> >m(1); //dummy
		istringstream ss(line);
		for(;ss>>s;){
			if(s!="|"){
				vector<int> v;
				v.push_back(0);
				for(auto &e:s)v.push_back(e-'0');
				m.push_back(v);
			}
		}
		m[0].resize(m[1].size());
		for(int i=1;i<m.size();i++)for(int j=1;j<m[0].size();j++)m[i][j]+=m[i][j-1];
		for(int j=1;j<m[0].size();j++)for(int i=1;i<m.size();i++)m[i][j]+=m[i-1][j];
		int N=1,s;
		for(;;N++){
			for(int j=0;j<m[0].size()-N;j++)for(int i=0;i<m.size()-N;i++){
				int s0=m[i+N][j+N]-m[i+N][j]-m[i][j+N]+m[i][j];
				if(j==0&&i==0)s=s0;
				else if(s!=s0)goto fail;
			}
			printf("%dx%d, %d\n",N,N,s);break;
			fail:;
		}
	}
}