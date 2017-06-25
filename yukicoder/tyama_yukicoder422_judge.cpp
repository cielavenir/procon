#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool chk(const string &x,const string &y){
	int yidx=0;
	for(int xidx=0;xidx<x.size();xidx++){
		if(x[xidx]!='-'){
			if(yidx>=y.size()||y[yidx]!=x[xidx])return false;
			yidx++;
		}
	}
	return yidx==y.size();
}
int calc(const string &x,const string &y){
	if(x.size()!=y.size())abort();
	int r=0,gap=0,mode=0;
	for(int i=0;i<x.size();i++){
		if(x[i]=='-'&&y[i]=='-')abort();
		if(x[i]=='-'||y[i]=='-'){
			int newmode=x[i]=='-'?1:2;
			if(newmode!=mode){
				if(gap)r+=9+2*(gap-1);
				gap=0;
				mode=newmode;
			}
			gap++;
		}else{
			if(gap)r+=9+2*(gap-1);
			gap=mode=0;
			if(x[i]!=y[i])r+=5;
		}
	}
	if(gap)r+=9+2*(gap-1);
	return r;
}

int main(int argc,char **argv){
	if(argc<3){
		cerr<<"gotoh_judge in.txt out.txt"<<endl;
		return 1;
	}
	int score;
	string s,t;
	cin>>score>>s>>t;
	{
		ifstream fin(argv[2]);
		int sc;
		fin>>sc;
		if(sc!=score)return -1; //invalid score.
	}
	{
		ifstream fin(argv[1]);
		string x,y;
		fin>>x>>x>>x>>y;
		if(!chk(s,x)||!chk(t,y))return -2; //invalid alignment.
	}
	if(calc(s,t)!=score)return 1; //wrong alignment.
	return 0;
}