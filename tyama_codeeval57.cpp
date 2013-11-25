#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define M 199
using namespace std;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}

bool f[49][49];
int main(){
	int h,w,i,j,x,y;
	string line;
	for(;getline(cin,line);cout<<endl){
		vector<pair<int,int> >d;
		d.push_back(make_pair(1,0));
		d.push_back(make_pair(0,1));
		d.push_back(make_pair(-1,0));
		d.push_back(make_pair(0,-1));

		memset(f,0,sizeof(f));
		vector<string>b=split(line,";");
		h=strtol(b[0].c_str(),NULL,10);
		w=strtol(b[1].c_str(),NULL,10);
		vector<string>a=split(b[2]," ");
		for(i=1;i<=h;i++)for(j=1;j<=w;j++)f[i][j]=1;

		x=y=1,f[y][x]=0;
		cout<<a[(y-1)*w+x-1];
		for(;;){
			for(i=0;i<4;i++){
				if(f[y+d[i].second][x+d[i].first]){
					rotate(d.begin(),d.begin()+i,d.end());
					x+=d[0].first;y+=d[0].second;
					f[y][x]=0;
					cout<<' '<<a[(y-1)*w+x-1];
					break;
				}
			}
			if(i==4)break;
		}
	}
}