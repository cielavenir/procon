#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<string>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	vector<pair<int,int> >B(N);
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		B[i].first=distance(A.begin(),find(A.begin(),A.end(),s));
		cin>>s>>s>>s;
		B[i].second=s=="good"?0:1;
		cin>>s;
	}
	vector<string>r;
	for(int i=0;i<1<<N;i++){
		vector<string>c;
		int j=0;
		for(;j<N;j++){
			if((i>>j&1)==0)c.push_back(A[j]);
			if(((i>>j&1)^B[j].second)!=(i>>B[j].first&1))break;
		}
		if(j==N){
			if(c.size()>r.size())for(j=0,r.clear();j<c.size();j++)r.push_back("ZZZ");
			if(c.size()==r.size())r=min(r,c);
		}
	}
	if(r.empty())cout<<"No answers"<<endl;
	else{
		sort(r.begin(),r.end());
		for(int i=0;i<r.size();i++)cout<<r[i]<<endl;
	}
}