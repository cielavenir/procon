#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc,char **argv){
	//freopen(argv[1],"r",stdin);
	string line,s;
	for(;getline(cin,line);){
		istringstream ss(line);
		vector<int> v;
		for(;ss>>s;)v.push_back(strtol(s.c_str(),NULL,10));
		int n=v.size();
		int r=0;
		for(int iter=0,h=n*4/5;;iter++){
			int f=0;
			for(int j=0;j<n-h;j++)if(v[j]>v[j+h]){
				swap(v[j],v[j+h]);
				r=iter+1;
				f=1;
			}
			if(h==1&&!f)break;
			h=h*4/5;
			if(!h)h=1;
		}
		printf("%d\n",r);
	}
}