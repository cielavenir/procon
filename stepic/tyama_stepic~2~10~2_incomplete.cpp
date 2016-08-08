/*
input:
https://app.box.com/rosalinddata/1/787051127/9128212829/1
https://app.box.com/download/external/f_9128212829/0/Salmonella_enterica.fasta?vanity_name=rosalinddata
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const char *bases="ATGC";
const char *cbases="TACG";
string revcom(string &s){
	string t=s;
	reverse(t.begin(),t.end());
	for(int i=0;i<t.size();i++){
		const char *p=strchr(bases,t[i]);
		if(p)t[i]=cbases[p-bases];
	}
	return t;
}
string s,s_revcom;
vector<string> t_max;
int c_max,K,D;
void dfs(string &t,int k){
	if(k==K){
		int i=0,j,d,c=0;
		for(;i<s.size()-k;i++){
			for(d=j=0;j<k;j++)d+=s[i+j]!=t[j];
			if(d<=D)c++;
			for(d=j=0;j<k;j++)d+=s_revcom[i+j]!=t[j];
			if(d<=D)c++;
		}
		if(c_max<c)c_max=c,t_max.clear();
		if(c_max==c)t_max.push_back(t);
	}else{
		int i=0;
		for(;i<4;i++){
			t+=bases[i];
			dfs(t,k+1);
			t.pop_back();
		}
	}
}
int main(){
	string line,t;
	getline(cin,line);
	for(;getline(cin,line);)s+=line;
	vector<int>m_idx;
#if 0
	{
		int m=99999,k=0,i=0;
		for(;i<s.size();i++){
			if(s[i]=='C'){
				if(m>--k)m=k,m_idx.clear();
				if(m==k)m_idx.push_back(i);
			}
			if(s[i]=='G')k++;
		}
		for(i=0;i<m_idx.size();i++)cout<<(m_idx[i]+0)<<endl;
	}
#else
	m_idx.push_back(3764855);
#endif
	K=9,D=1;
	s=s.substr(m_idx[0],1000);
	s_revcom=revcom(s);
	dfs(t,0);
	int i=0;
	cout<<c_max<<endl;
	for(;i<t_max.size();i++)cout<<t_max[i]<<endl; //not good...
}