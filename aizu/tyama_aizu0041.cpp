#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int reversepoland(string &exp){
	int i;
	
	vector<string> token;
	for(i=0;i<exp.length();i++)token.push_back(exp.substr(i,1));
	vector<int> resolveNumber;
	vector<string> resolveString;
	for(i=0;i<token.size();i++){
		char *p=NULL;
		int d=strtol(token[i].c_str(),&p);
		if(p-token[i].c_str()==token[i].size()){
			resolveNumber.push_back(d);
			resolveString.push_back(token[i]);
		}else{
			//if(resolveNumber.size()<2){printf("stack few\n");return 0;}
			int d2=resolveNumber[resolveNumber.size()-1],d1=resolveNumber[resolveNumber.size()-2];
			resolveNumber.pop_back(),resolveNumber.pop_back();
			string s2=resolveString[resolveString.size()-1],s1=resolveString[resolveString.size()-2];
			resolveString.pop_back(),resolveString.pop_back();
			int ret;
			
			if(token[i]=="+"){ret=d1+d2;}
			else if(token[i]=="-"){ret=d1-d2;}
			else if(token[i]=="*"){ret=d1*d2;}
			//else if(token[i]=="/"){ret=d1/d2;}
			//else if(token[i]=="%"){ret=d1%d2;}
			//else if(token[i]=="**"){ret=pow(d1,d2);}
			//else{printf("unknown OP %s\n",token[i].c_str());return 0;}
			
			resolveNumber.push_back(ret);
			resolveString.push_back("("+s1+token[i]+s2+")"); //this won't emit "optimized" expression. full of parens.
		}
	}
	//if(resolveNumber.size()!=1){printf("result stack not 1");return 0;}
	if(resolveNumber[0]!=10)return 0;
	printf("%s\n",resolveString[0].c_str());
	return 1;
}
// nnnnooo,nnnonoo,nnonnoo,nnnoono,nnonono
int x[][3]={{4,5,6},{3,5,6},{2,5,6},{3,4,6},{2,4,6}};
char *op="+-*";
main(){
	int a[4],i,j,k,l,L=sizeof(x)/sizeof(*x);
	string s="0000000";
	for(;scanf("%d%d%d%d",a,a+1,a+2,a+3),a[0]|a[1]|a[2]|a[3];){
		sort(a,a+4);
		do{
			for(i=0;i<L;i++){
				for(k=j=0;j<7;j++){
					if(find(x[i],x[i]+3,j)==x[i]+3)s[j]=a[k++]+'0';
				}
				for(j=0;j<3;j++){
					s[x[i][0]]=op[j];
					for(k=0;k<3;k++){
						s[x[i][1]]=op[k];
						for(l=0;l<3;l++){
							s[x[i][2]]=op[l];
							if(reversepoland(s))goto done;
						}
					}
				}
			}
		}while(next_permutation(a,a+4));
		puts("0");
		done:;
	}
}