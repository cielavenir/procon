#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string s;
	int m=99999,k=0,i=0;
	vector<int>m_idx;
	for(cin>>s;i<s.size();i++){
		if(s[i]=='C'){
			if(m>--k)m=k,m_idx.clear();
			if(m==k)m_idx.push_back(i);
		}
		if(s[i]=='G')k++;
	}
	for(i=0;i<m_idx.size();i++)cout<<(m_idx[i]+0)<<endl;
}