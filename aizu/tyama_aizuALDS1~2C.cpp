#include<vector>
#include<string>
#include<iostream>
#include<numeric>
using namespace std;
int main(){
	int n,i=0,j,c;
	string s;
	vector<string>v;
	for(cin>>n;i<n;i++)cin>>s,v.push_back(s);
	vector<string>a=v;
	for(i=0;i<n;i++)for(j=0;j<n-i-1;j++)if(a[j][1]>a[j+1][1])s=a[j],a[j]=a[j+1],a[j+1]=s;
	string sorted=accumulate(a.begin(),a.end(),string(),[](const string &x,const string &y){return x+" "+y;}).substr(1);
	cout<<sorted<<endl;
	cout<<"Stable"<<endl;
	a=v;
	for(i=0;i<n;i++){
		for(c=i,j=i+1;j<n;j++)if(a[j][1]<a[c][1])c=j;
		if(c>i)s=a[i],a[i]=a[c],a[c]=s;
	}
	string sorted2=accumulate(a.begin(),a.end(),string(),[](const string &x,const string &y){return x+" "+y;}).substr(1);
	cout<<sorted2<<endl;
	cout<<(sorted==sorted2?"Stable":"Not stable")<<endl;
}