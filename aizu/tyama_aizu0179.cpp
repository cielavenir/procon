#include<iostream>
#include<queue>
#include<map>
using namespace std;
int main(){
	string s,t;for(int i,n,f;cin>>s,s!="0";){
		queue<string>q;
		map<string,int>d;d[s]=1;
		for(q.push(s);q.size();){
			s=q.front();q.pop();
			n=s.length();
			for(f=i=0;i<n-1;i++)if(s[i]!=s[i+1]){
				t=s;t[i]=t[i+1]=(char)('r'+'g'+'b'-s[i]-s[i+1]);f++;
				if(!d[t])d[t]=d[s]+1,q.push(t);
			}
			if(!f){cout<<d[s]-1<<endl;goto N;}
		}
		cout<<"NA"<<endl;N:;
	}
}