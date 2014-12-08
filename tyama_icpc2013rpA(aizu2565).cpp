#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define UNK 2000000000

bool valid(vector<int>&v){
	int i;
	for(i=1;i<v.size();i+=2){
		if(v[i-1]<=v[i])return false;
	}
	for(i=2;i<v.size();i+=2){
		if(v[i-1]>=v[i])return false;
	}
	return true;
}

int main(){
	int n,i,j;
	string s;
	for(;cin>>n,n;){
		vector<int>unknown;
		vector<int>num;
		vector<int>v;
		v.push_back(1000010000);
		num.push_back(1000010000);
		for(i=0;i<n;i++){
			cin>>s;
			if(s=="x"){
				unknown.push_back(i+1);
				v.push_back(0);
			}else{
				int n=strtol(s.c_str(),NULL,10);
				num.push_back(n);
				v.push_back(n);
			}
		}
		if(v.size()%2==0){
			v.push_back(1000010001);
			num.push_back(1000010001);
		}else{
			v.push_back(-1000010001);
			num.push_back(-1000010001);
		}

		int _min=UNK,_max=UNK;
		if(unknown.empty()){
			if(valid(v))cout<<"ambiguous"<<endl;
			else cout<<"none"<<endl;
			continue;
		}
/*
		for(i=1;i<unknown.size();i++)if(unknown[i-1]+1==unknown[i]){
			cout<<"none"<<endl;
			goto next;
		}
*/
		for(i=0;i<unknown.size();i++){
			if(unknown[i]%2==0){
				if(_min==UNK)_min=max(v[unknown[i]-1],v[unknown[i]+1])+1;
				_min=max(_min,max(v[unknown[i]-1],v[unknown[i]+1])+1);
			}else{
				if(_max==UNK)_max=min(v[unknown[i]-1],v[unknown[i]+1])-1;
				_max=min(_max,min(v[unknown[i]-1],v[unknown[i]+1])-1);
			}
		}
		if(_min==UNK||_max==UNK)cout<<"ambiguous"<<endl;
		else if(_min>_max)cout<<"none"<<endl;
		else{
			for(j=0;j<unknown.size();j++)v[unknown[j]]=_min;
			if(valid(v)){
				if(_min==_max)cout<<_min<<endl;
				else cout<<"ambiguous"<<endl;
			}else{
				cout<<"none"<<endl;
			}
		}

/*
		sort(num.begin(),num.end());
		for(i=1;i<num.size();i++){
			for(j=0;j<unknown.size();j++)v[unknown[j]]=num[i-1]+1;
			if(valid(v)){
				if(num[i-1]+1==num[i]-1)cout<<num[i-1]+1<<endl;
				else cout<<"ambiguous"<<endl;
				goto next;
			}
		}
		cout<<"none"<<endl;
		next:;
*/
	}
}