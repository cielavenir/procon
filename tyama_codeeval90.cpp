#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
double x[19],y[19],m[19][19],a,b,rad=.0175,eps=1e-8;
int main(){
	string s;
	double a,b;
	int n=0,i=0,j;
	vector<int>v_min,v;
	for(;getline(cin,s);n++){
		istringstream ss(s.substr(s.find("(")+1));
		ss>>a,ss.ignore(),ss>>b;
		//sscanf(s.substr(s.find("(")).c_str(),"(%lf, %lf)",&a,&b);
		x[n]=a*rad,y[n]=b*rad;
		v.push_back(n);
	}
	for(;i<n;i++)for(j=i+1;j<n;j++){
		m[i][j]=m[j][i]=acos(sin(x[i])*sin(x[j])+cos(x[i])*cos(x[j])*cos(y[i]-y[j]));
		//hypotl(x[i]-x[j],y[i]-y[j]);
	}
	b=1e8;
	for(;next_permutation(v.begin()+1,v.end());){
		for(a=i=0;i<v.size()-1;i++)a+=m[v[i]][v[i+1]];
		if(a-eps<b)b=a,v_min=v;
	}
	for(i=0;i<v_min.size();i++)cout<<v_min[i]+1<<endl;
}