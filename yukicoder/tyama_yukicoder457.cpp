#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int solve(char *s,int len){
	vector<int>al;
	vector<int>ar;
	vector<int>ah(len);
	vector<int>ast;
	for(int i=0;i<len;i++){
		if(s[i]=='('){
			al.push_back(i);
		}else if(s[i]==')'){
			ar.push_back(i);
		}else if(s[i]=='^'){
			ah[i]++;
		}else if(s[i]=='*'){
			ast.push_back(i);
		}
	}
	for(int i=1;i<len;i++)ah[i]+=ah[i-1];
	int ret=0;
	auto ist=ast.begin();
	auto ir=ar.begin();
	for(auto &l:al){
		int hidx=lower_bound(ah.begin()+l,ah.end(),ah[l]+2)-ah.begin();
		ist=lower_bound(ist,ast.end(),hidx);
		if(ist==ast.end())break;
		ret+=ar.end()-(ir=lower_bound(ir,ar.end(),*ist));
	}
	return ret;
}
char s[10001];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	printf("%d ",solve(s,len));
	reverse(s,s+len);
	for(int i=0;i<len;i++){
		if(s[i]=='(')s[i]=')';
		else if(s[i]==')')s[i]='(';
	}
	printf("%d\n",solve(s,len));
}
