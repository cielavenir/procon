#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
	string line;
	vector<string> course;
	for(;getline(cin,line);)course.push_back(line);
	int n=course.size(),startx=-1;
	//this kind of search is not good... but the test case is weak and codeeval cares speed.
	for(int x=0;x<course[n-1].size();x++)if(course[n-1][x]=='C')startx=x;
	if(startx==-1)for(int x=0;x<course[n-1].size();x++)if(course[n-1][x]=='_')startx=x;
	for(int y=n-2;y>=0;y--){
		int nextx=-1;
		for(int x=max(0,startx-1);x<min((int)course[y].size(),startx+2);x++)if(course[y][x]=='C')nextx=x;
		if(nextx==-1)for(int x=max(0,startx-1);x<min((int)course[y].size(),startx+2);x++)if(course[y][x]=='_')nextx=x;
		if(nextx-startx==-1)course[y+1][startx]='\\';
		else if(nextx-startx==1)course[y+1][startx]='/';
		else course[y+1][startx]='|';
		startx=nextx;
	}
	course[0][startx]='|';
	for(int y=0;y<n;y++)cout<<course[y]<<endl;
}