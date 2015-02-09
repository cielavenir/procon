#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
int main(){
	string suit,line;
	for(;getline(cin,suit),suit!="#";){
		vector<unique_ptr<istringstream>> v;
		for(int i=0;i<4;i++){
			getline(cin,line);
			//lovely "use of deleted function std::basic_istringstream"...
			//http://stackoverflow.com/a/12018358/2641271
			//Note: gcc 5.0.0 head and clang don't have this issue.
			v.push_back(unique_ptr<istringstream>(new istringstream(line)));
		}
		vector<string>card(4);
		vector<int>num(4);
		vector<int>point(4);
		for(int Z=0,winner=0;Z<13;Z++){
			for(int i=0;i<4;i++)(*v[i])>>card[i];
			for(int i=0;i<4;i++){
				num[i]=card[i][1]==suit[0]?26:card[i][1]==card[winner][1]?13:0;
				num[i]+=card[i][0]=='T'?10:card[i][0]=='J'?11:card[i][0]=='Q'?12:card[i][0]=='K'?13:card[i][0]=='A'?14:card[i][0]-'0';
			}
			winner=distance(num.begin(),max_element(num.begin(),num.end()));
			point[winner]++;
		}
		if(point[0]+point[2]>point[1]+point[3]){
			printf("NS %d\n",point[0]+point[2]-6);
		}else{
			printf("EW %d\n",point[1]+point[3]-6);
		}
	}
}