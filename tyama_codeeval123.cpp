#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
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
vector<int> split_int(string &str, const char *delim){
	vector<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtol(str.c_str(),NULL,10));
	}
	return result;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,B,i,j,k,remain,siz;
	string line;
	for(;getline(cin,line);){
		vector<int>item;
		{
			vector<string>a=split(line," ");
			string b=a[0].substr(1);
			item=split_int(b,",");
			N=item.size();
			B=strtol(a[1].c_str(),NULL,10);
		}
		remain=*max_element(item.begin(),item.end())-1;
		//if(B>1000000+remain+1){puts("0");continue;}
		vector<vector<vector<int> > >bag(B+remain/2);
		bag[0].push_back(vector<int>(N));
		for(i=0;i<N;i++){
			for(j=item[i];j<B+remain/2;j++){
				siz=bag[j-item[i]].size();
				for(k=0;k<siz;k++){
					bag[j].push_back(bag[j-item[i]][k]);
					bag[j].rbegin()->at(i)++;
				}
			}
		}
		if(bag[B].empty()){
			for(i=0;i<remain/2&&bag[B+i].empty();i++);
			printf("%d\n",i);
		}else{
			sort(bag[B].begin(),bag[B].end());
			for(i=0;i<bag[B].size();i++){
				putchar('[');
				for(j=0;j<bag[B][i].size();j++){
					printf(j<bag[B][i].size()-1?"%d,":"%d]",bag[B][i][j]);
				}
			}
			puts("");
		}
	}
}