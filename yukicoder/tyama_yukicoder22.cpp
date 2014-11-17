#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;k--;
	string s;
	cin>>s;
	vector<int>v(s.size());
	stack<int>st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='(')st.push(i);
		else{
			int x=st.top();st.pop();
			v[x]=i,v[i]=x;
		}
	}
	printf("%d\n",v[k]+1);
}