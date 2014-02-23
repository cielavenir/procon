#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool triangle(vector<int> &row, vector<int> &col){
	if(row[0]==row[1]){
		int len=col[1]-col[0];
		return len>0 && col[2]==col[1] && row[2]==row[0]+len;
	}else{
		int len=row[1]-row[0];
		return len>0 && col[0]==col[1] && row[2]==row[1] && col[2]==col[1]+len;
	}
}

bool parallelogram(vector<int> &row,vector<int> &col){
	if(row[0]==row[1]){
		int len=col[1]-col[0];
		return len>0 && row[2]==row[3] && col[3]-col[2]==len && row[2]-row[0]==len && (col[2]==col[0] || col[2] == col[1]);
	}else{
		int len=row[1]-row[0];
		return len>0 && col[0]==col[1] && col[2]==col[3] && row[1]==row[2] && row[3]-row[2]==len && col[2]-col[1]==len;
	}
}

bool hexagon(vector<int> &row,vector<int> &col){
	int len=col[1]-col[0];
	return len>0 && row[0]==row[1] && col[2]==col[0] && row[2]==row[0]+len && col[3]==col[1]+len && row[3]==row[2] && col[4]==col[1] && row[4]==row[2]+len && col[5]==col[3] && row[5]==row[4];
}

void rowcol(vector<int> &p,vector<int> &row,vector<int> &col){
	for(int i=0;i<p.size();i++){
		int head=1,inc=1;
		for(;p[i]>=head+inc;inc++)head+=inc;
		row[i]=inc;
		col[i]=p[i]-head;
	}
}

int solve(vector<int> points){
	sort(points.begin(),points.end());
	vector<int>row(points.size()),col(points.size());
	rowcol(points,row,col);
	if(points.size()==3 && triangle(row,col))return 3;
	if(points.size()==4 && parallelogram(row,col))return 4;
	if(points.size()==6 && hexagon(row,col))return 6;
	return 0;
}

int main(){
	map<int,string>m;
	m[0]="are not the vertices of an acceptable figure";
	m[3]="are the vertices of a triangle";
	m[4]="are the vertices of a parallelogram";
	m[6]="are the vertices of a hexagon";
	string line;
	for(;getline(cin,line);){
		vector<int> points;
		int x;
		istringstream sin(line);
		for(;sin>>x;)points.push_back(x),cout<<x<<' ';
		cout<<m[solve(points)]<<endl;
	}
}