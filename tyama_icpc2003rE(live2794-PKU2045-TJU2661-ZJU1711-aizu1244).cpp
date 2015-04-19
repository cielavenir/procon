#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

unordered_map<string,int> tbl;
int calc(vector<string>&v,int s){
	vector<int>z;
	for(;v[s]!=")";){
		if(v[s]=="("){
			z.push_back(calc(v,s+1));
			int cnt=1;
			for(s++;cnt;s++){
				if(v[s]=="(")cnt++;
				if(v[s]==")")cnt--;
			}
		}else if('0'<=v[s][0]&&v[s][0]<='9'){
			z[z.size()-1]*=strtol(v[s].c_str(),NULL,10);
			s++;
		}else{
			z.push_back(tbl[v[s]]);
			s++;
		}
	}
	int i=0,r=0;
	for(;i<z.size();i++)r+=z[i];
	return r;
}
int main(){
	string mole;
	for(;cin>>mole;){
		if(mole=="END_OF_FIRST_PART")break;
		int n;
		cin>>n;
		tbl[mole]=n;
	}
	for(;cin>>mole&&mole!="0";){
		vector<string> v;
		//tokenize
		for(int i=0;i<mole.size();){
			if(mole[i]=='('){
				v.push_back("("),i++;
			}else if(mole[i]==')'){
				v.push_back(")"),i++;
			}else if('0'<=mole[i]&&mole[i]<='9'){
				int j=i+1;
				for(;'0'<=mole[j]&&mole[j]<='9';j++);
				v.push_back(mole.substr(i,j-i));
				i=j;
			}else if('A'<=mole[i]&&mole[i]<='Z'){
				int j=i+1;
				for(;'a'<=mole[j]&&mole[j]<='z';j++);
				string x=mole.substr(i,j-i);
				if(tbl.find(x)==tbl.end()){cout<<"UNKNOWN"<<endl;goto NEXT;}
				v.push_back(x);
				i=j;
			}
		}
		v.push_back(")");
		cout<<calc(v,0)<<endl;
NEXT:;
	}
}