#include <string>
#include <cstdio>
#include <cstdlib>
char S[9];main(){
	int q,n,r,i;std::string s;
	for(scanf("%d",&q);q--;printf("%d\n",r))
		for(r=0,scanf("%d",&n);n>9;r++)
			for(sprintf(S,"%d",n),s=S,n=0,i=1;i<s.length();i++)n=std::max(n,atoi(s.substr(0,i).c_str())*atoi(s.substr(i).c_str()));
}