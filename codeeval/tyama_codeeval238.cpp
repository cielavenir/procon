#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc,char **argv){
	//freopen(argv[1],"r",stdin);
	string line;
	for(;getline(cin,line);){
		vector<string>v;
		string s,t;
		istringstream ss(line);
		for(;ss>>s;ss>>t)v.push_back(s);
		int H=v.size(),W=v[0].size(),r=0;
		for(int i=0;i<H-1;i++)for(int j=0;j<W-1;j++){
			int x=0;
			for(int k=0;k<2;k++)for(int l=0;l<2;l++){
				if(v[i+k][j+l]=='c')x|=1;
				if(v[i+k][j+l]=='o')x|=2;
				if(v[i+k][j+l]=='d')x|=4;
				if(v[i+k][j+l]=='e')x|=8;
			}
			if(x==15)r++;
		}
		printf("%d\n",r);
	}
}