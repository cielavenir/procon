#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long double x[99],y[99],m[99][99];
int main(int argc, char **argv){
	ifstream fin(argv[1]);
	string s;
	long double a,b;
	int n=0,i=0,j;
	vector<int>v_min,v;
	for(;getline(fin,s);n++){
		istringstream ss(s.substr(s.find("(")+1));
		ss>>a>>b;
		x[n]=a,y[n]=b;
		v.push_back(n);
	}
	for(;i<n;i++)for(j=i+1;j<n;j++){
		m[i][j]=m[j][i]=hypotl(x[i]-x[j],y[i]-y[j]);
	}
	b=999;
	for(;next_permutation(v.begin()+1,v.end());){
		for(a=i=0;i<v.size()-1;i++)a+=m[v[i]][v[i+1]];
		if(a-(long double)1e-7<b)b=a,v_min=v;
	}
	for(i=0;i<v.size();i++)cout<<v_min[i]+1<<endl;
}