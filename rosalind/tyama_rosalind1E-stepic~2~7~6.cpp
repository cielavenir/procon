#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string s;
	int m=0,k=0,i=0;
	vector<int>m_idx;
	m_idx.push_back(0);
	for(cin>>s;i<s.size();i++){
		if(s[i]=='C'){
			if(m>--k)m=k,m_idx.clear();
		}
		if(s[i]=='G')k++;
		if(m==k)m_idx.push_back(i);
	}
	for(i=0;i<m_idx.size();i++){
		if(i)cout<<' ';
		cout<<(m_idx[i]+1);
	}
	cout<<endl;
}